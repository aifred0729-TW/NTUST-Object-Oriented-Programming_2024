#include <Windows.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool runProcess();
bool readFile(std::vector<std::string>& lines);
void getNumberFromLine(std::string line, std::vector<long>& numbers);
void runBubbleSort(std::vector<long>& numbers);
void countNumber(std::string& result, std::vector<long>& numbers);
void addToBuffer(std::string& result, long count, int grade);

int main() {
    runProcess();
    return 0;
}

bool runProcess() {
    using namespace std;

    unsigned int   i = 0;
    vector<long>   numbers;
    vector<string> lines;
    string         result = "";

    if (!readFile(lines))
        return false;

    for (i = 0; i < lines.size(); i++) {
        getNumberFromLine(lines[i], numbers);
        runBubbleSort(numbers);
        countNumber(result, numbers);
        numbers.clear();
    }

    HANDLE fileHandle =
      CreateFileA((LPCSTR) "grades.Output", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    WriteFile(fileHandle, (LPCVOID)result.c_str(), result.size(), NULL, NULL);

    return true;
}

bool readFile(std::vector<std::string>& lines) {
    using namespace std;

    string   oneLine;
    ifstream fileHandle;

    fileHandle.open("grade.txt");

    if (fileHandle.is_open()) {
        while (getline(fileHandle, oneLine)) {
            lines.push_back(oneLine);
        }
    } else {
        cout << "Huh ?" << endl;
        return false;
    }

    return true;
}

void getNumberFromLine(std::string line, std::vector<long>& numbers) {
    using namespace std;

    stringstream ss("");
    long         tmpNumber;

    ss << line;
    while (ss >> tmpNumber) {
        numbers.push_back(tmpNumber);
    }

    return;
}

void runBubbleSort(std::vector<long>& numbers) {
    unsigned int i         = 0;
    unsigned int j         = 0;
    long         tmpNumber = 0;

    for (i = numbers.size() - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                tmpNumber      = numbers[j];
                numbers[j]     = numbers[j + 1];
                numbers[j + 1] = tmpNumber;
            }
        }
    }

    return;
}

void countNumber(std::string& result, std::vector<long>& numbers) {
    using namespace std;

    int          count = 0;
    unsigned int i     = 0;
    unsigned int j     = 0;

    for (i = 0; i < numbers.size() - 1; i++) {
        count++;
        if (numbers[i] != numbers[i + 1]) {
            addToBuffer(result, count, numbers[i]);
            count = 0;
            if (numbers[i] + 1 != numbers[i + 1]) {
                for (j = numbers[i] + 1; j < numbers[i + 1]; j++) {
                    addToBuffer(result, 0, j);
                }
            }
            continue;
        }
    }
    count++;
    addToBuffer(result, count, numbers[numbers.size() - 1]);
    return;
}

void addToBuffer(std::string& result, long count, int grade) {
    result += std::to_string(count);
    result += " grade(s) of ";
    result += std::to_string(grade);
    result += '\n';
    return;
}