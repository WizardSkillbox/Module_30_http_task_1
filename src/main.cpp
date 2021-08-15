#include <iostream>
#include <string>

#include <cpr/cpr.h>

using namespace std;

static string GetStringFromStream(const string &message) {
    string str;
    while (true) {
        cout << message << endl;
        while (str.empty()) {
            getline(cin, str);
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(LLONG_MAX, '\n');
        } else {
            break;
        }
    }
    return str;
}

int main() {
    while (true) {
        cpr::Response response;
        string cmd = GetStringFromStream("Enter command (get|post|put|delete|patch|exit)");
        if (cmd == "get") {
            response = cpr::Get(cpr::Url("http://httpbin.org/get"));
        } else if (cmd == "post") {
            response = cpr::Post(cpr::Url("http://httpbin.org/post"));
        } else if (cmd == "put") {
            response = cpr::Put(cpr::Url("http://httpbin.org/put"));
        } else if (cmd == "delete") {
            response = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        } else if (cmd == "patch") {
            response = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
        } else if (cmd == "exit") {
            break;
        } else {
            cout << "Error. Incorrect command" << endl;
        }

        cout << response.text << endl;
    }

    return 0;
}
