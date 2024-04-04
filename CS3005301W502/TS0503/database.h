#include <iostream>
#include <vector>

class Database {
    private:
    typedef struct {
        char firstName[25];
        char lastName[30];
        char phone[15];
    } StRec;

    int                maxLimit;
    std::vector<StRec> dataContainer;

    public:
    Database() {
        maxLimit = INT_MAX;
    }

    Database(int maxLimit) {
        this->maxLimit = maxLimit;
    }

    void insertData(std::string firstName, std::string lastName, std::string phone);
    void deleteData(std::string firstName, std::string lastName, std::string phone);
    void searchData(std::string firstName, std::string lastName, std::string phone);
    void printData();
    int  checkIsExist(std::string firstName, std::string lastName, std::string phone);
};