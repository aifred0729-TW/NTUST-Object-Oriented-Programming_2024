#include <iostream>
#include <string>
#include <vector>

bool runProcess();
int  runLevenshteinDistance(std::string firstLine, std::string secondLine);

int main() {
    while (true) {
        if (runProcess())
            continue;
        return 0;
    }
}

bool runProcess() {
    using namespace std;

    string firstLine  = "";
    string secondLine = "";

    if (!getline(cin, firstLine))
        return false;
    getline(cin, secondLine);

    cout << runLevenshteinDistance(firstLine, secondLine) << endl;

    return true;
}

int runLevenshteinDistance(std::string firstLine, std::string secondLine) {
    using namespace std;

    int lengthOfFirstLine  = firstLine.size() + 1;
    int lengthOfSecondLine = secondLine.size() + 1;

    vector<vector<int>> matrix;
    matrix.resize(lengthOfFirstLine);

    /*
     * kiitten
     * sitting
     *
     * X -----------------
     * | X X s i t t i n g
     * | X 0 1 2 3 4 5 6 7
     * | k 1 1 2 3 4 5 6 7
     * | i 2 2 1 2 3 4 5 6
     * | i 3 3 2 2 3 3 4 5
     * | t 4 4 3 2 2 3 4 5
     * | t 5 5 4 3 2 3 4 5
     * | e 6 6 5 4 3 3 4 5
     * | n 7 7 6 5 4 4 3 4
     *
     */

    // Initialize Matrix
    for (unsigned int i = 0; i < lengthOfSecondLine; i++) {
        matrix[0].push_back(i);
    }

    for (unsigned int i = 1; i < lengthOfFirstLine; i++) {
        matrix[i].push_back(i);
    }

    for (unsigned int row = 1; row < lengthOfFirstLine; row++) {
        for (unsigned int column = 1; column < lengthOfSecondLine; column++) {
            int minValue = 0;

            if (firstLine[row - 1] == secondLine[column - 1]) {
                minValue = min(min(matrix[row - 1][column - 1], matrix[row - 1][column] + 1), matrix[row][column - 1] + 1);
                matrix[row].push_back(minValue);
            } else {
                minValue = min(min(matrix[row - 1][column - 1], matrix[row - 1][column]), matrix[row][column - 1]) + 1;
                matrix[row].push_back(minValue);
            }
        }
    }

    return matrix[lengthOfFirstLine - 1][lengthOfSecondLine - 1];
}