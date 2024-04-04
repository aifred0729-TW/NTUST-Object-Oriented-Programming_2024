#include <iostream>
#include <sstream>
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

    unsigned int i                = 0;
    unsigned int xLength          = 0;
    string       preProcessString = "";
    string       xDecimal         = "";

    string       x = "";
    unsigned int m = 0;
    unsigned int n = 0;
    char         c = ' ';

    if (!(getline(cin, preProcessString)) && cin.eof())
        return false;

    stringstream ss("");
    ss << preProcessString;

    ss >> x;
    ss >> m;
    ss >> n;
    ss >> c;

    // Get decimal of x if exist, or add "."
    if (find(x.begin(), x.end(), '.') != x.end()) {
        xDecimal = x.substr(x.find('.') + 1);
    } else {
        xDecimal = "";
        x += '.';
    }

    // Add decimal pattern / remove . / Conbine integer and decimal
    if (xDecimal.length() < n) {
        x += string(n - xDecimal.length(), '0');
    } else if (n == 0) {
        x = x.substr(0, x.find('.'));
    } else {
        x = x.substr(0, x.find('.') + 1 + n);
    }

    // output char pattern
    if (x.length() < m) {
        for (i = 0; i < m - x.length(); i++) {
            cout << c;
        }
    }

    cout << x << endl;

    return true;
}