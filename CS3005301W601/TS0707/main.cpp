#include <iostream>
#include <string>
#include <vector>

bool        runProcess();
void        getOne(std::string& a, int i);
std::string doAddition(std::string a, std::string b);
std::string doSubtraction(std::string a, std::string b);
std::string doMultiplication(std::string a, std::string b);

int main() {
    while (true) {
        if (runProcess())
            continue;
        return 0;
    }
}

bool runProcess() {
    using namespace std;

    string a = "";
    string b = "";

    if (!(cin >> a))
        return false;
    cin >> b;

    if (a[0] == '-' && b[0] == '-') {
        string tmp = "";
        a.erase(0, 1);
        b.erase(0, 1);

        cout << '-' << doAddition(a, b) << endl;

        tmp = doSubtraction(a, b);
        if (tmp[0] == '-') {
            tmp.erase(0, 1);
            cout << tmp << endl;
        } else {
            cout << '-' << tmp << endl;
        }

        cout << doMultiplication(a, b) << endl;
    } else if (a[0] == '-') {
        string tmp = "";
        a.erase(0, 1);

        cout << doSubtraction(b, a) << endl;
        cout << '-' << doAddition(a, b) << endl;
        cout << '-' << doMultiplication(a, b) << endl;
    } else if (b[0] == '-') {
        b.erase(0, 1);
        cout << doSubtraction(a, b) << endl;
        cout << '-' << doAddition(a, b) << endl;
        cout << '-' << doMultiplication(a, b) << endl;
    } else {
        cout << doAddition(a, b) << endl;
        cout << doSubtraction(a, b) << endl;
        cout << doMultiplication(a, b) << endl;
    }

    return true;
}

std::string doAddition(std::string a, std::string b) {
    using namespace std;

    unsigned int tmp = 0;

    string result = "";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() < b.size()) {
        a += string(b.size() - a.size(), '0');
    } else {
        b += string(a.size() - b.size(), '0');
    }

    for (unsigned int i = 0; i < a.size(); i++) {
        tmp += (a[i] - '0') + (b[i] - '0');
        if (tmp >= 10) {
            result += (tmp % 10) + '0';
            tmp /= 10;
            continue;
        }
        result += tmp + '0';
        tmp = 0;
    }

    if (tmp != 0)
        result += tmp + '0';

    reverse(result.begin(), result.end());

    for (unsigned int i = 0; i < result.size(); i++) {
        if (result[i] != '0') {
            result.erase(0, i);
            break;
        } else if (i == result.size() - 1) {
            result.erase(0, i);
            break;
        }
    }

    return result;
}

std::string doSubtraction(std::string a, std::string b) {
    using namespace std;

    int  tmp   = 0;
    bool isNeg = false;

    string result = "";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() > b.size()) {
        b += string(a.size() - b.size(), '0');
    } else if (a.size() < b.size()) {
        a += string(b.size() - a.size(), '0');
    }

    for (unsigned int i = a.size() - 1; i >= 0; i--) {
        if (a[i] - '0' < b[i] - '0') {
            swap(a, b);
            isNeg = true;
            break;
        } else if (a[i] - '0' > b[i] - '0') {
            isNeg = false;
            break;
        } else if (i == 0) {
            break;
        }
    }

    for (unsigned int i = 0; i < a.size(); i++) {
        tmp = 0;
        if (a[i] - '0' < b[i] - '0') {
            getOne(a, i + 1);
            tmp += 10;
        }
        tmp += (a[i] - '0') - (b[i] - '0');
        result += tmp + '0';
    }

    reverse(result.begin(), result.end());

    for (unsigned int i = 0; i < result.size(); i++) {
        if (result[i] != '0') {
            result.erase(0, i);
            break;
        } else if (i == result.size() - 1) {
            result.erase(0, i);
            break;
        }
    }

    if (isNeg)
        result = '-' + result;

    return result;
}

void getOne(std::string& a, int i) {
    if (a[i] - '0' == 0) {
        a[i] = '9';
        getOne(a, i + 1);
        return;
    }
    a[i] -= 1;
    return;
}

std::string doMultiplication(std::string a, std::string b) {
    using namespace std;

    vector<string> sumInteger;
    string         tmpInteger = "";

    int tmp = 0;

    if (a.size() < b.size())
        swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (unsigned int i = 0; i < b.size(); i++) {
        tmp = 0;
        for (unsigned int j = 0; j < a.size(); j++) {
            tmp += (b[i] - '0') * (a[j] - '0');
            if (tmp >= 10) {
                tmpInteger += (tmp % 10) + '0';
                tmp /= 10;
                continue;
            }
            tmpInteger += tmp + '0';
            tmp = 0;
        }
        if (tmp != 0)
            tmpInteger += tmp + '0';

        reverse(tmpInteger.begin(), tmpInteger.end());
        tmpInteger += string(i, '0');

        sumInteger.push_back(tmpInteger);
        tmpInteger = "";
    }

    tmpInteger = "0";

    for (unsigned int i = 0; i < sumInteger.size(); i++) {
        tmpInteger = doAddition(tmpInteger, sumInteger[i]);
    }

    return tmpInteger;
}