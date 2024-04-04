#include <iostream>
#include <string>
#include <vector>

#define EMPTY_SPACE "   "

void runProcess(std::string number);
void addOneChar(std::string& stageOne, std::string& stageTwo, std::string& stageThree, char cmp);
void returnSpace(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnOne(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnTwo(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnThree(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnFour(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnFive(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnSix(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnSeven(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnEight(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnNine(std::string& stageOne, std::string& stageTwo, std::string& stageThree);
void returnZero(std::string& stageOne, std::string& stageTwo, std::string& stageThree);

int main() {
    using namespace std;

    string number = "";

    while (getline(cin, number)) {
        runProcess(number);
    }
    return 0;
}

void runProcess(std::string number) {
    using namespace std;

    string stageOne   = "";
    string stageTwo   = "";
    string stageThree = "";

    for (unsigned int i = 0; i < number.size(); i++) {
        addOneChar(stageOne, stageTwo, stageThree, number[i]);
    }

    cout << stageOne << endl;
    cout << stageTwo << endl;
    cout << stageThree << endl;
    return;
}

void addOneChar(std::string& stageOne, std::string& stageTwo, std::string& stageThree, char cmp) {
    switch (cmp) {
        case ' ':
            // returnSpace(stageOne, stageTwo, stageThree);
            break;
        case '1':
            returnOne(stageOne, stageTwo, stageThree);
            break;
        case '2':
            returnTwo(stageOne, stageTwo, stageThree);
            break;
        case '3':
            returnThree(stageOne, stageTwo, stageThree);
            break;
        case '4':
            returnFour(stageOne, stageTwo, stageThree);
            break;
        case '5':
            returnFive(stageOne, stageTwo, stageThree);
            break;
        case '6':
            returnSix(stageOne, stageTwo, stageThree);
            break;
        case '7':
            returnSeven(stageOne, stageTwo, stageThree);
            break;
        case '8':
            returnEight(stageOne, stageTwo, stageThree);
            break;
        case '9':
            returnNine(stageOne, stageTwo, stageThree);
            break;
        case '0':
            returnZero(stageOne, stageTwo, stageThree);
            break;
    }
    return;
}

void returnSpace(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += EMPTY_SPACE;
    stageTwo += EMPTY_SPACE;
    stageThree += EMPTY_SPACE;
}

void returnOne(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += EMPTY_SPACE;
    stageTwo += "  |";
    stageThree += "  |";
    return;
}

void returnTwo(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += " _ ";
    stageTwo += " _|";
    stageThree += "|_ ";
    return;
}

void returnThree(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += " _ ";
    stageTwo += " _|";
    stageThree += " _|";
    return;
}

void returnFour(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += EMPTY_SPACE;
    stageTwo += "|_|";
    stageThree += "  |";
    return;
}

void returnFive(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += " _ ";
    stageTwo += "|_ ";
    stageThree += " _|";
    return;
}

void returnSix(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += " _ ";
    stageTwo += "|_ ";
    stageThree += "|_|";
    return;
}

void returnSeven(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += " _ ";
    stageTwo += "  |";
    stageThree += "  |";
    return;
}

void returnEight(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += " _ ";
    stageTwo += "|_|";
    stageThree += "|_|";
    return;
}

void returnNine(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += " _ ";
    stageTwo += "|_|";
    stageThree += " _|";
    return;
}

void returnZero(std::string& stageOne, std::string& stageTwo, std::string& stageThree) {
    stageOne += " _ ";
    stageTwo += "| |";
    stageThree += "|_|";
    return;
}
