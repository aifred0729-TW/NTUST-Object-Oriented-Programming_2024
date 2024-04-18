#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Polynomial {
    public:
    int rowSize = 0;

    std::vector<double> row;

    Polynomial() {
        row.push_back(0);
        rowSize = row.size();
    }

    Polynomial(double* param, int size) {
        for (int i = 0; i < size; i++) {
            row.push_back(param[i]);
        }
        if (size == 0) {
            row.push_back(0);
            size++;
        }
        rowSize = size;
    }

    Polynomial(const Polynomial& poly) {
        row     = poly.row;
        rowSize = poly.rowSize;
    }

    int           mySize();
    friend double evaluate(const Polynomial poly, const double var);

    double& operator[](const int index);

    Polynomial operator=(const Polynomial poly);

    Polynomial        operator+(const Polynomial poly);
    Polynomial        operator+(const double num);
    friend Polynomial operator+(const double num, const Polynomial poly);

    Polynomial        operator-(const Polynomial poly);
    Polynomial        operator-(const double num);
    friend Polynomial operator-(const double num, const Polynomial poly);

    Polynomial        operator*(const Polynomial poly);
    Polynomial        operator*(const double num);
    friend Polynomial operator*(const double num, const Polynomial poly);
};