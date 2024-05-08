#pragma once
#include <iostream>
#include <sstream>
#include <string>

class School {
    private:
    std::string name = "";

    int studentAmount         = 0;
    int studentAmountNextYear = 0;

    public:
    School(std::string schoolName, float amount) {
        name                  = schoolName;
        studentAmount         = amount;
        studentAmountNextYear = amount;
    }

    void  admissions(float amount);
    bool  dropouts(float amount);
    void  transfer(float amount, School& toSchool);
    void  nextYearSubtract(float amount);
    void  nextYearAddition(float amount);
    float getNextYear();

    std::string returnFormatOutput();

    friend std::ostream& operator<<(std::ostream&, School& s);
};

class PrivateSchool: public School {
    private:
    int dropoutCount = 0;

    public:
    PrivateSchool(std::string schoolName, int amount): School(schoolName, amount) {
        ;
    }

    void dropouts(float amount);

    std::string operator<<(PrivateSchool);
};

class PublicSchool: public School {
    public:
    PublicSchool(std::string schoolName, int amount): School(schoolName, amount) {
        ;
    }

    void apply_growth();
    void dropouts(float amount);
    void transfer(float amount, School& toSchool);

    std::string operator<<(PublicSchool);
};