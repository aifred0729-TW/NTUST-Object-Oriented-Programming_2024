#include "Month.h"

#include <iostream>

Month::Month() {
    month = 1;
}

Month::Month(char first, char second, char third) {
    switch (first) {
        case 'J':
            if (second == 'a')
                month = 1;
            else if (third == 'n')
                month = 6;
            else if (third == 'l')
                month = 7;
            else
                month = 1;

            break;
        case 'M':
            if (third == 'r')
                month = 3;
            else if (third == 'y')
                month = 5;
            else
                month = 1;

            break;
        case 'A':
            if (second == 'p')
                month = 4;
            else if (second == 'u')
                month = 8;
            else
                month = 1;

            break;
        case 'F':
            month = 2;
            break;
        case 'S':
            month = 9;
            break;
        case 'O':
            month = 10;
            break;
        case 'N':
            month = 11;
            break;
        case 'D':
            month = 12;
            break;
    }
    return;
}

Month::Month(int monthInt) {
    month = monthInt < 1 || monthInt > 12 ? 1 : monthInt;
}

Month::~Month() {
    ;
}

void Month::inputInt() {
    int tmp = 0;
    std::cin >> tmp;
    if (tmp < 1 || tmp > 12)
        month = 1;
    else
        month = tmp;
    return;
}

void Month::inputStr() {
    char first, second, third;

    std::cin >> first;
    std::cin >> second;
    std::cin >> third;

    switch (first) {
        case 'J':
            if (second == 'a')
                month = 1;
            else if (third == 'n')
                month = 6;
            else if (third == 'l')
                month = 7;
            else
                month = 1;

            break;
        case 'M':
            if (third == 'r')
                month = 3;
            else if (third == 'y')
                month = 5;
            else
                month = 1;

            break;
        case 'A':
            if (second == 'p')
                month = 4;
            else if (second == 'u')
                month = 8;
            else
                month = 1;

            break;
        case 'F':
            month = 2;
            break;
        case 'S':
            month = 9;
            break;
        case 'O':
            month = 10;
            break;
        case 'N':
            month = 11;
            break;
        case 'D':
            month = 12;
            break;
        default:
            month = 1;
            break;
    }
    return;
}

void Month::outputInt() {
    std::cout << month;
    return;
}

void Month::outputStr() {
    using namespace std;

    switch (month) {
        case 1:
            cout << "Jan";
            break;
        case 2:
            cout << "Feb";
            break;
        case 3:
            cout << "Mar";
            break;
        case 4:
            cout << "Apr";
            break;
        case 5:
            cout << "May";
            break;
        case 6:
            cout << "Jun";
            break;
        case 7:
            cout << "Jul";
            break;
        case 8:
            cout << "Aug";
            break;
        case 9:
            cout << "Sep";
            break;
        case 10:
            cout << "Oct";
            break;
        case 11:
            cout << "Nov";
            break;
        case 12:
            cout << "Dec";
            break;
    }
    return;
}

Month Month::nextMonth() {
    return month + 1 == 13 ? Month(1) : Month(month + 1);
}
