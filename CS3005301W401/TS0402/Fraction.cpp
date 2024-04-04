#include "Fraction.h"

#include <iomanip>

void Fraction::setNumerator(int nu) {
    numerator = nu;
    return;
}

void Fraction::setDenominator(int de) {
    denominator = de;
    return;
}

void Fraction::getDouble() {
    double resultOfDouble = (double)numerator / denominator;
    if (resultOfDouble > (int)resultOfDouble || resultOfDouble < (int)resultOfDouble) {
        cout << fixed << setprecision(6) << resultOfDouble << endl;
    } else {
        cout << (int)resultOfDouble << endl;
    }

    return;
}

void Fraction::outputReducedFraction() {
    using namespace std;

    int greatestCommonFactor = GDC(numerator, denominator);

    numerator /= greatestCommonFactor;
    denominator /= greatestCommonFactor;

    if (denominator == 1) {
        cout << numerator << endl;
    } else {
        cout << numerator << '/' << denominator << endl;
    }

    return;
}
