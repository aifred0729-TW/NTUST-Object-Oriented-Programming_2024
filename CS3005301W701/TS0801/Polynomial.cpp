#include "Polynomial.h"

#include <algorithm>
#include <iostream>
#include <vector>

int Polynomial::mySize() {
    int size = 0;
    for (size = row.size() - 1; size > -1; size--)
        if (row[size] != 0)
            break;
    return size + 1;
}

double evaluate(const Polynomial poly, const double var) {
    double result = 0.0f;
    for (unsigned int i = 0; i < poly.row.size(); i++) {
        result += (pow(var, i) * poly.row[i]);
    }
    return result;
}

double& Polynomial::operator[](const int index) {
    if (row.size() < index + 1)
        row.resize(index + 1);
    return row[index];
}

Polynomial Polynomial::operator=(const Polynomial poly) {
    row.clear();
    row     = poly.row;
    rowSize = poly.rowSize;
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial poly) {
    Polynomial lPoly;
    lPoly.row     = row;
    lPoly.rowSize = rowSize;

    Polynomial rPoly = poly;

    int lSize = lPoly.row.size();
    int rSize = rPoly.row.size();

    if (lSize < rSize)
        lPoly.row.resize(rSize);
    else if (lSize > rSize)
        rPoly.row.resize(lSize);

    Polynomial result;

    for (unsigned int i = 0; i < std::max(lSize, rSize); i++) {
        result[i] = lPoly[i] + rPoly[i];
    }

    return result;
}

Polynomial Polynomial::operator+(const double num) {
    Polynomial tmp;
    tmp.row     = row;
    tmp.rowSize = rowSize;
    tmp[0] += num;
    return tmp;
}

Polynomial operator+(const double num, const Polynomial poly) {
    Polynomial tmp = poly;
    tmp[0] += num;
    return tmp;
}

Polynomial Polynomial::operator-(const Polynomial poly) {
    Polynomial lPoly;
    lPoly.row        = row;
    lPoly.rowSize    = rowSize;
    Polynomial rPoly = poly;

    int lSize = lPoly.row.size();
    int rSize = rPoly.row.size();

    if (lSize < rSize)
        lPoly.row.resize(rSize);
    else if (lSize > rSize)
        rPoly.row.resize(lSize);

    Polynomial result;

    for (unsigned int i = 0; i < std::max(lSize, rSize); i++) {
        result[i] = lPoly[i] - rPoly[i];
    }

    return result;
}

Polynomial Polynomial::operator-(const double num) {
    Polynomial tmp;
    tmp.row     = row;
    tmp.rowSize = rowSize;
    tmp[0] -= num;
    return tmp;
}

Polynomial operator-(const double num, const Polynomial poly) {
    Polynomial tmp = poly;
    tmp[0]         = num - tmp[0];
    for (unsigned int i = 1; i < tmp.row.size(); i++) {
        tmp[i] *= -1;
    }
    return tmp;
}

Polynomial Polynomial::operator*(const Polynomial poly) {
    Polynomial lPoly;
    lPoly.row        = row;
    lPoly.rowSize    = rowSize;
    Polynomial rPoly = poly;

    Polynomial result;

    for (unsigned int i = 0; i < lPoly.row.size(); i++) {
        for (unsigned int j = 0; j < rPoly.row.size(); j++) {
            result[i + j] += lPoly[i] * rPoly[j];
        }
    }

    return result;
}

Polynomial Polynomial::operator*(const double num) {
    Polynomial tmp;
    tmp.row     = row;
    tmp.rowSize = rowSize;
    for (unsigned int i = 0; i < tmp.row.size(); i++) {
        tmp[i] *= num;
    }
    return tmp;
}

Polynomial operator*(const double num, const Polynomial poly) {
    Polynomial tmp = poly;
    for (unsigned int i = 0; i < tmp.row.size(); i++) {
        tmp[i] *= num;
    }
    return tmp;
}