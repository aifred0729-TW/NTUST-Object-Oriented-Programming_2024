#include <iostream>
#include <sstream>
#include <vector>

void getNumber(std::vector<long> &numbers);
void runBubbleSort(std::vector<long> &numbers);
void countNumber(std::vector<long> &numbers);

int main() {
    using namespace std;

    vector<long> numbers;
    getNumber(numbers);

    cout << "N\tcount" << endl;
    countNumber(numbers);

    return 0;
}

void getNumber(std::vector<long> &numbers) {
    using namespace std;

    string       userInput = "";
    stringstream ss("");
    int          tmpNumber = 0;

    getline(cin, userInput);
    ss << userInput;

    while (ss >> tmpNumber) {
        numbers.push_back(tmpNumber);
    }

    runBubbleSort(numbers);
    return;
}

void runBubbleSort(std::vector<long> &numbers) {
    unsigned int i         = 0;
    unsigned int j         = 0;
    long         tmpNumber = 0;

    for (i = numbers.size() - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (numbers[j] < numbers[j + 1]) {
                tmpNumber      = numbers[j];
                numbers[j]     = numbers[j + 1];
                numbers[j + 1] = tmpNumber;
            }
        }
    }

    return;
}

void countNumber(std::vector<long> &numbers) {
    using namespace std;

    unsigned int i         = 0;
    unsigned int j         = 0;
    long         tmpNumber = 0;
    int          count     = 0;

    for (i = 0; i < numbers.size() - 1; i++) {
        count++;
        if (numbers[i] != numbers[i + 1]) {
            cout << numbers[i] << '\t' << count << endl;
            count = 0;
            continue;
        }
    }

    count++;
    cout << numbers[numbers.size() - 1] << '\t' << count;
    return;
}