#include "user.h"

#include <iostream>

namespace {
std::string username = "";
bool        isValid() {
    if (username.size() != 8)
        return false;
    for (char usernameChar: username) {
        if (!isalpha(usernameChar))
            return false;
    }
    return true;
}
}  // namespace

namespace Authenticate {
void inputUserName() {
    using namespace std;
    do {
        cout << "Enter your username (8 letters only)" << endl;
        cin >> username;
    } while (!isValid());
}

std::string getUserName() {
    return username;
}
}  // namespace Authenticate
