#include "NumberSet.h"

#include <iostream>
#include <string>

int NumberSet::resolveFourBaseByString(std::string inputString) {
    using namespace std;

    int value = 0;
    reverse(inputString.begin(), inputString.end());
    for (unsigned int i = 0; i < inputString.size(); i++) {
        switch (inputString[i]) {
            case 'U':
                value += 1 * pow(4, i);
                break;
            case 'C':
                value += 2 * pow(4, i);
                break;
            case 'D':
                value += 3 * pow(4, i);
                break;
        }
    }
    return value;
}

void NumberSet::runOperation(char opcode) {
    using namespace std;
    switch (opcode) {
        case 'A':
            number2 += number1;
            break;
        case 'R':
            number2 /= 4;
            break;
        case 'L':
            number2 *= 4;
            break;
    }
}

void NumberSet::checkYesOrNo() {
    using namespace std;
    if (number2 == answer)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return;
}