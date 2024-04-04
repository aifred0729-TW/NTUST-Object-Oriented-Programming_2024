#include "Point.h"

#include <iostream>

void Point::Set(float x, float y) {
    coordinateContainer[0] = x;
    coordinateContainer[1] = y;
    return;
}

void Point::Move(float x, float y) {
    coordinateContainer[0] += x;
    coordinateContainer[1] += y;
    return;
}

void Point::Rotate() {
    std::swap(coordinateContainer[0], coordinateContainer[1]);
    coordinateContainer[1] == 0 ? 0 : coordinateContainer[1] *= -1;
    return;
}

void Point::Reflect() {
    coordinateContainer[0] == 0 ? 0 : coordinateContainer[0] *= -1;
    coordinateContainer[1] == 0 ? 0 : coordinateContainer[1] *= -1;
    return;
}

float Point::GetHorizontal() const {
    return this->coordinateContainer[0];
}

float Point::GetVertical() const {
    return this->coordinateContainer[1];
}