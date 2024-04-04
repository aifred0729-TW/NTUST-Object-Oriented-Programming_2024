#include <iostream>
#include <string>
#include <vector>

#include "NumberSet.h"

void runProcess();

int main() {
    using namespace std;

    unsigned int round = 0;

    while (cin >> round) {
        cout << "COWCULATIONS OUTPUT" << endl;

        for (unsigned int i = 0; i < round; i++) {
            runProcess();
        }

        cout << "END OF OUTPUT" << endl;
    }

    return 0;
}

void runProcess() {
    using namespace std;

    string n1S = "";
    string n2S = "";
    string ans = "";

    vector<char> opcode;

    cin >> n1S;
    cin >> n2S;

    char tmp;

    for (unsigned int i = 0; i < 3; i++) {
        cin >> tmp;
        opcode.push_back(tmp);
    }
    cin >> ans;

    NumberSet num(n1S, n2S, ans);

    for (unsigned int i = 0; i < 3; i++) {
        num.runOperation(opcode[i]);
    }

    num.checkYesOrNo();

    return;
}