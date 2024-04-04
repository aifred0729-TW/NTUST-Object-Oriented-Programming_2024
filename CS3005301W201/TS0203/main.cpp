#include <math.h>

#include <iostream>
#include <string>

bool runProcess();

int main() {
    while (true) {
        if (runProcess())
            continue;
        return 0;
    }
}

bool runProcess() {
    using namespace std;

    string inputString;

    if (!(cin >> inputString) && cin.eof())
        return false;

    long messageLength = inputString.length();
    int  borderLength  = int(ceil(sqrt(messageLength)));

    for (unsigned int i = 0; i < borderLength; i++) {
        for (unsigned int j = i; j < pow(borderLength, 2); j += borderLength) {
            if (j >= messageLength)
                break;
            cout << inputString[j];
        }
        cout << endl;
    }

    return true;
}