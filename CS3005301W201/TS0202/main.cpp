#include <fstream>
#include <iostream>
#include <vector>

void getHighScores();
void readFile(std::vector<std::string> &name, std::vector<long long> &scores, int &elementCount);
void runBubbleSort(std::vector<std::string> &names, std::vector<long long> &scores, int elementCount);

int main() {
    getHighScores();
    return 0;
}

void getHighScores() {
    using namespace std;

    vector<string>    names;
    vector<long long> scores;
    int               elementCount = 0;

    readFile(names, scores, elementCount);
    runBubbleSort(names, scores, elementCount);

    for (int i = 0; i < 3; i++) {
        cout << names[i] << endl << scores[i] << endl;
    }
}

void readFile(std::vector<std::string> &names, std::vector<long long> &scores, int &elementCount) {
    using namespace std;

    long     tmpScore;
    string   tmpName;
    ifstream fileHandle;

    fileHandle.open("scores.txt");

    if (fileHandle.is_open()) {
        while (true) {
            if (!(fileHandle >> tmpName) && fileHandle.eof())
                return;
            fileHandle >> tmpScore;
            names.push_back(tmpName);
            scores.push_back(tmpScore);
            elementCount++;
        }
    } else {
        cout << "Huh ?" << endl;
    }
}

void runBubbleSort(std::vector<std::string> &names, std::vector<long long> &scores, int elementCount) {
    using namespace std;

    int    tmpScore;
    string tmpName;

    for (unsigned int i = elementCount - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (scores[j] < scores[j + 1]) {
                tmpName       = names[j];
                tmpScore      = scores[j];
                names[j]      = names[j + 1];
                scores[j]     = scores[j + 1];
                names[j + 1]  = tmpName;
                scores[j + 1] = tmpScore;
            }
        }
    }

    return;
}