#include "Atoi.h"

#include <iostream>
#include <string>

Atoi::Atoi() {
    beTrans = "";
}

Atoi::Atoi(string s) {
    Atoi::SetString(s);
}

void Atoi::SetString(string s) {
    if (s[0] == '-') {
        s.erase(0, 1);
        isNeg = true;
    } else {
        isNeg = false;
    }
    beTrans = s;
    return;
}

const std::string Atoi::GetString() {
    return isNeg ? '-' + beTrans : beTrans;
}

int Atoi::Length() {
    return beTrans.size();
}

bool Atoi::IsDigital() {
    using namespace std;
    for (unsigned int i = 0; i < beTrans.size(); i++) {
        if (48 > beTrans[i] - '0' > 57) {
            return false;
        }
    }
    return true;
}

int Atoi::StringToInteger() {
    using namespace std;
    string tmp    = beTrans;
    int    result = 0;
    reverse(tmp.begin(), tmp.end());
    for (unsigned int i = 0; i < tmp.size(); i++) {
        result += (tmp[i] - '0') * pow(10, i);
    }
    return isNeg ? result * -1 : result;
}