#include <iostream>
#include "Shisensho.h"

void Shisensho::initializeMap() {
    map.resize(row);
    return;
}

void Shisensho::pushByRow(int row, int value) {
    map[row].push_back(value);
    return;
}

bool Shisensho::checkIsPair(int srcRow, int srcCol, int dstRow, int dstCol) {

}