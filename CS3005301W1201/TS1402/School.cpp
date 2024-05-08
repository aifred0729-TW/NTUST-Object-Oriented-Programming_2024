#include "School.h"

void School::admissions(float amount) {
    if (amount <= 0)
        return;
    studentAmount = (float)studentAmount + amount;
    return;
}

bool School::dropouts(float amount) {
    if (amount <= 0)
        return true;
    else if (studentAmount - amount < 0)
        return true;
    studentAmount = (float)studentAmount - amount;
    return false;
}

void School::transfer(float amount, School &toSchool) {
    if (dropouts(amount))
        return;
    toSchool.admissions(amount);
    return;
}

void School::nextYearSubtract(float amount) {
    studentAmountNextYear -= amount;
    return;
}

void School::nextYearAddition(float amount) {
    studentAmountNextYear += amount;
}

float School::getNextYear() {
    return studentAmountNextYear;
}

std::string School::returnFormatOutput() {
    using namespace std;
    string result = "";
    string tmp    = "";

    stringstream ss("");

    result += name;
    result += '\t';

    ss << studentAmount;
    ss >> tmp;
    ss.clear();

    result += tmp;
    result += '\t';

    ss << studentAmountNextYear;
    ss >> tmp;
    ss.clear();

    result += tmp;

    return result;
}

std::ostream &operator<<(std::ostream &o, School &s) {
    o << s.returnFormatOutput();
    return o;
}

void PrivateSchool::dropouts(float amount) {
    if (dropoutCount >= 1)
        nextYearSubtract(100);
    dropoutCount++;
    School::dropouts(amount);
    return;
}

std::string PrivateSchool::operator<<(PrivateSchool) {
    return School::returnFormatOutput();
}

void PublicSchool::apply_growth() {
    School::nextYearAddition(getNextYear() * 0.05);
    return;
}

void PublicSchool::dropouts(float amount) {
    if (amount >= 100) {
        School::nextYearSubtract(getNextYear() * 0.05);
    }
    School::dropouts(amount);
    return;
}

void PublicSchool::transfer(float amount, School &toSchool) {
    if (amount >= 100) {
        School::nextYearSubtract(getNextYear() * 0.05);
    }
    School::transfer(amount, toSchool);
    return;
}

std::string PublicSchool::operator<<(PublicSchool) {
    return School::returnFormatOutput();
}