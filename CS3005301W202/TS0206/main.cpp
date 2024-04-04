#include <iostream>
// SortIncludes
#include <string>

void   process(double pay);
double computeTax(double pay, double taxOffset, double taxRate, double addationTax);

int main() {
    double pay = 0;
    while (true) {
        if (!(std::cin >> pay) && std::cin.eof())
            return 0;
        process(pay);
    }
}

void process(double pay) {
    using namespace std;

    double tax;

    if (pay <= 750) {
        tax = computeTax(pay, 0, 0.01, 0);
    } else if (pay <= 2250) {
        tax = computeTax(pay, 750, 0.02, 7.5);
    } else if (pay <= 3750) {
        tax = computeTax(pay, 2250, 0.03, 37.5);
    } else if (pay <= 5250) {
        tax = computeTax(pay, 3750, 0.04, 82.5);
    } else if (pay <= 7000) {
        tax = computeTax(pay, 5250, 0.05, 142.5);
    } else {
        tax = computeTax(pay, 7000, 0.06, 230);
    }
    printf("%.2f\n", tax);
    return;
}

double computeTax(double pay, double taxOffset, double taxRate, double addationTax) {
    return ((pay - taxOffset) * taxRate) + addationTax;
}
