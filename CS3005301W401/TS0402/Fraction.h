#ifndef Fraction_H
#define Fraction_H
#include <iomanip>
#include <iostream>
using namespace std;

class Fraction {
    private:
    int numerator;
    int denominator;

    int GDC(int a, int b) {
        return a % b == 0 ? b : GDC(b, a %= b);
    }

    public:
    void setNumerator(int nu);
    void setDenominator(int de);
    void getDouble();
    void outputReducedFraction();
};

#endif  // Fraction_H