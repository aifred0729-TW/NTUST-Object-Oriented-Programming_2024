#include "sudoku.h"

#include <iostream>

void Sudoku::getElement(unsigned int row, int element) {
    map[row].push_back(element);
    return;
}

bool Sudoku::scanXY() {
    using namespace std;

    int tmpX = 0;
    int tmpY = 0;

    for (unsigned int row = 0; row < 9; row++) {
        tmpX = 0;
        tmpY = 0;
        for (unsigned int column = 0; column < 9; column++) {
            tmpX += map[row][column];
            tmpY += map[column][row];
        }
        if (tmpX != 45 || tmpY != 45)
            return false;
    }
    return true;
}

bool Sudoku::scanArea() {
    using namespace std;

    int tmpArea = 0;

    for (unsigned int row = 0; row < 9; row += 3) {
        for (unsigned int column = 0; column < 9; column += 3) {
            tmpArea = 0;
            for (unsigned int i = row; i < row + 3; i++) {
                for (unsigned int j = column; j < column + 3; j++) {
                    tmpArea += map[i][j];
                }
            }
            if (tmpArea != 45)
                return false;
        }
    }
    return true;
}