#include <math.h>

#include <iostream>
#include <vector>

void   runProcess(long round);
double computeAverage(double totalScore, long round);
double computeStandardDeviation(std::vector<double> numbers, double average, long round);

int main() {
    long round = 0;

    while (true) {
        if (!(std::cin >> round) && std::cin.eof())
            return 0;
        runProcess(round);
    }
}

void runProcess(long round) {
    using namespace std;

    double         tmp               = 0;
    double         totalScore        = 0;
    double         average           = 0;
    double         standardDeviation = 0;
    vector<double> numbers;

    for (unsigned int i = 1; i < round + 1; i++) {
        cin >> tmp;
        numbers.push_back(tmp);
        totalScore += tmp;
    }

    average           = computeAverage(totalScore, round);
    standardDeviation = computeStandardDeviation(numbers, average, round);

    cout << "Average:" << average << "\t"
         << "Standard deviation:" << standardDeviation << endl;
}

double computeAverage(double totalScore, long round) {
    return totalScore / round;
}

double computeStandardDeviation(std::vector<double> numbers, double average, long round) {
    using namespace std;

    double standardDeviation = 0;

    for (long i = 0; i < round; i++) {
        standardDeviation += pow((numbers[i] - average), 2);
    }
    return sqrt(standardDeviation / round);
}