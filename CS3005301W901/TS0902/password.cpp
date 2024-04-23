#include "password.h"

#include <iostream>

namespace {
std::string password = "";
bool        isValid() {
    if (password.size() < 8)
        return false;
    for (char passwordChar: password) {
        if (!isalpha(passwordChar))
            return true;
    }
    return false;
}
}  // namespace

namespace Authenticate {
void inputPassword() {
    using namespace std;
    do {
        cout << "Enter your password (at least 8 characters "
             << "and at least one non-letter)" << endl;
        cin >> password;
    } while (!isValid());
}

std::string getPassword() {
    return password;
}
}  // namespace Authenticate
