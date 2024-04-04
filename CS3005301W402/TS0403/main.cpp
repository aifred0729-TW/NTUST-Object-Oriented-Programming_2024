#include <iostream>

bool runProcess();
int  GDC(int a, int b);

int main() {
    while (true) {
        if (runProcess())
            continue;
        return 0;
    }
}

bool runProcess() {
    using namespace std;

    int a = 0;
    int b = 0;

    if (!(cin >> a) && cin.eof())
        return false;
    cin >> b;

    cout << GDC(a, b) << endl;
    return true;
}

int GDC(int a, int b) {
    return a % b == 0 ? b : GDC(b, a %= b);
}