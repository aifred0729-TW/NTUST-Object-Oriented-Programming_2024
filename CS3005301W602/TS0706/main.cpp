#include <iostream>
#include "Shisensho.h"

void getInputs(Shisensho &obj);

int main() {
    using namespace std;

    Shisensho obj(6, 6);
    obj.initializeMap();
    getInputs(obj);

    int srcRow = 0;
    int srcCol = 0;
    int dstRow = 0;
    int dstCol = 0;

    while (cin >> srcRow) {
        cin >> srcCol;
        cin >> dstRow;
        cin >> dstCol;
    }

    obj.test();

    return 0;
}

void getInputs(Shisensho &obj) {
    using namespace std;

    int tmp = 0;

    for (unsigned int i = 0; i < 6; i++) {
        for (unsigned int j = 0; j < 6; j++) {
            cin >> tmp;
            obj.pushByRow(i, tmp);
        }
    }
    return;
}

