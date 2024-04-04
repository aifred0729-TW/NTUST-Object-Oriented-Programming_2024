#include <iomanip>
#include <iostream>

bool        runProcess();
long double computeLogOfMaxNumber(long long bit);
int         computeFactorial(long double limitLog);

int main() {
    while (true) {
        if (runProcess())
            continue;
        return 0;
    }
}

bool runProcess() {
    using namespace std;

    int                year = 0;
    unsigned long long bit  = 0;

    if (!(cin >> year) && cin.eof())
        return false;

    bit = 4 * pow(2, (year - 1900) / 10);

    // log(4) = log(2) * 2
    // log(2) * bit = (2^bit)
    // log 可以縮小數字讓他比較不會 overflow

    long double limitLog = computeLogOfMaxNumber(bit);

    int factorialOfN = computeFactorial(limitLog);
    cout << factorialOfN << endl;

    return true;
}

long double computeLogOfMaxNumber(long long bit) {
    return log(2) * bit;
}

int computeFactorial(long double limitLog) {
    using namespace std;

    unsigned int factorialOfN = 1;
    long double  maxNumberLog = 0.0;

    while (true) {
        if (maxNumberLog > limitLog)
            return factorialOfN - 2;
        maxNumberLog += log(factorialOfN);
        factorialOfN++;
    }
}