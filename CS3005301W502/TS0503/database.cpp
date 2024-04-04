#include "database.h"

#include <iostream>
#include <string>
#include <vector>

void Database::insertData(std::string firstName, std::string lastName, std::string phone) {
    using namespace std;

    if (checkIsExist(firstName, lastName, phone) != -1 || dataContainer.size() >= maxLimit) {
        cout << "Insert Error" << endl;
        return;
    }

    StRec data;

    strcpy_s(data.firstName, firstName.c_str());
    strcpy_s(data.lastName, lastName.c_str());
    strcpy_s(data.phone, phone.c_str());
    dataContainer.push_back(data);

    return;
}

void Database::deleteData(std::string firstName, std::string lastName, std::string phone) {
    using namespace std;

    int index = checkIsExist(firstName, lastName, phone);

    if (index == -1) {
        cout << "Delete Error" << endl;
        return;
    }

    dataContainer.erase(dataContainer.begin() + index);
    return;
}

void Database::searchData(std::string firstName, std::string lastName, std::string phone) {
    using namespace std;

    int index = checkIsExist(firstName, lastName, phone);

    if (index == -1) {
        cout << "Search Error" << endl;
        return;
    }

    cout << index << endl;
    return;
}

void Database::printData() {
    using namespace std;

    if (dataContainer.size() <= 0) {
        cout << "Print Error" << endl;
        return;
    }

    for (unsigned int i = 0; i < dataContainer.size(); i++) {
        cout << dataContainer[i].firstName << " " << dataContainer[i].lastName << " " << dataContainer[i].phone << endl;
    }
    return;
}

int Database::checkIsExist(std::string firstName, std::string lastName, std::string phone) {
    using namespace std;

    for (unsigned int i = 0; i < dataContainer.size(); i++) {
        if (
          !strcmp(dataContainer[i].firstName, firstName.c_str()) && !strcmp(dataContainer[i].lastName, lastName.c_str())
          && !strcmp(dataContainer[i].phone, phone.c_str())) {
            return i;
        }
    }

    return -1;
}