#include "Point.h"

void Point::Set(int vertical, int horizontal) {
    this->vertical   = vertical;
    this->horizontal = horizontal;
    return;
}

void Point::Move(int x, int y) {
    this->vertical += x;
    this->horizontal += y;
    return;
}
void Point::Rotate() {
    int tmp    = 0;
    tmp        = vertical;
    vertical   = horizontal;
    horizontal = tmp;
    horizontal *= -1;
    return;
}