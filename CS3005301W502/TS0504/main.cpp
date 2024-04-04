#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "sudoku.h"

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

    int          tmp  = 0;
    string       line = "";
    stringstream ss;

    Sudoku instancedSudoku;

    for (unsigned int row = 0; row < 9; row++) {
        if (!getline(cin, line))
            return false;
        for (unsigned int i = 0; i < line.size(); i++) {
            if (line[i] == ',')
                line[i] = ' ';
        }

        ss << "";
        ss.clear();
        ss << line;
        for (unsigned int i = 0; i < 9; i++) {
            ss >> tmp;
            instancedSudoku.getElement(row, tmp);
        }
    }

    if (!instancedSudoku.scanXY() || !instancedSudoku.scanArea()) {
        cout << "False" << endl;
    } else {
        cout << "True" << endl;
    }
    getchar();
    return true;
}