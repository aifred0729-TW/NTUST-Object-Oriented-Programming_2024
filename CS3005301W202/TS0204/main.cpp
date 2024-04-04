#include <iostream>
// SortIncludes
#include <string>
#include <vector>

void process(int inputCount);

int main() {
    int inputCount = 0;
    while (true) {
        if (!(std::cin >> inputCount) && std::cin.eof())
            return 0;
        process(inputCount);
    }
}

void process(int inputCount) {
    using namespace std;

    int            maxNameLength = 0, maxSalaryLength = 0, maxBonusLength = 0;
    string         tmpName, tmpSalary, tmpBonus;
    vector<string> name, salary, bonus;

    for (int i = 0; i < inputCount; i++) {
        cin >> tmpName >> tmpSalary >> tmpBonus;
        maxNameLength   = (maxNameLength   < tmpName.length())   ? tmpName.length()   : maxNameLength;
        maxSalaryLength = (maxSalaryLength < tmpSalary.length()) ? tmpSalary.length() : maxSalaryLength;
        maxBonusLength  = (maxBonusLength  < tmpBonus.length())  ? tmpBonus.length()  : maxBonusLength;
        name.push_back(tmpName);
        salary.push_back(tmpSalary);
        bonus.push_back(tmpBonus);
    }

    for (int i = 0; i < inputCount; i++) {
        cout << string(maxNameLength       - name[i].length(),   ' ') << name[i]   << '|'
             << string(maxSalaryLength + 2 - salary[i].length(), ' ') << salary[i] << '|'
             << string(maxBonusLength  + 2 - bonus[i].length(),  ' ') << bonus[i]  << endl;
    }
    return;
}