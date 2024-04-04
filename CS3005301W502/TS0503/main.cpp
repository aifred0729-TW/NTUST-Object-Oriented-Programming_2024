#include <iostream>
#include <regex>

#include "database.h"

bool runProcess();
bool runOpcodeCheck(std::string& opcode);
bool runSecurityCheck(std::string& firstName, std::string& lastName, std::string& phone);

int main() {
    while (true) {
        if (runProcess())
            continue;
        return 0;
    }
}

bool runProcess() {
    using namespace std;

    string opcode    = "";
    string firstName = "";
    string lastName  = "";
    string phone     = "";

    Database instancedDB(10);

    while (cin >> opcode) {
        if (!runOpcodeCheck(opcode)) {
            cout << "Input Error" << endl;
            continue;
        }

        if (opcode == "print") {
            instancedDB.printData();
            continue;
        }

        cin >> firstName >> lastName >> phone;

        if (!runSecurityCheck(firstName, lastName, phone)) {
            cout << "Input Error" << endl;
            continue;
        }

        if (opcode == "insert") {
            instancedDB.insertData(firstName, lastName, phone);
        } else if (opcode == "delete") {
            instancedDB.deleteData(firstName, lastName, phone);
        } else if (opcode == "search") {
            instancedDB.searchData(firstName, lastName, phone);
        }
    }

    return false;
}

bool runOpcodeCheck(std::string& opcode) {
    using namespace std;
    regex opcodeCompare("^(insert|delete|search|print)$");
    return regex_match(opcode, opcodeCompare);
}

bool runSecurityCheck(std::string& firstName, std::string& lastName, std::string& phone) {
    using namespace std;

    regex phoneCompare("^[0-9]+$");

    if (firstName.size() >= 25 || lastName.size() >= 30 || phone.size() >= 15)
        return false;
    return regex_match(phone, phoneCompare);
}