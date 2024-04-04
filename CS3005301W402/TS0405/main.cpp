#include <iostream>
#include <vector>

bool runProcess();
long getCycle(unsigned int i, long cycle);

int main() {
    while (true) {
        if (runProcess())
            continue;
        return 0;
    }
}

bool runProcess() {
    using namespace std;

    unsigned int i = 0;
    unsigned int j = 0;

    unsigned int initOfi = 0;
    unsigned int initOfj = 0;

    long cycle    = 0;
    long maxCycle = 0;
    long tmpCycle = 0;

    if (!(cin >> initOfi) && cin.eof())
        return false;
    cin >> initOfj;

    cout << initOfi << ' ' << initOfj << ' ';

    for (i = min(initOfi, initOfj); i < max(initOfi, initOfj) + 1; i++) {
        tmpCycle = getCycle(i, cycle);
        maxCycle = maxCycle < tmpCycle ? tmpCycle : maxCycle;
    }

    cout << maxCycle << endl;
}

long getCycle(unsigned int i, long cycle) {
    if (i == 1)
        return cycle + 1;
    return i % 2 == 0 ? getCycle(i / 2, cycle + 1) : getCycle(i * 3 + 1, cycle + 1);
}
