#include <iostream>
#include <math.h>
#include <vector>

bool runProcess(long round);
double computeAverage(double average, long round);
double computeStandardDeviation(std::vector<double> storedNumbers, double average, long round);

int main() {
	long round = 0;
	while (true) {
		if (!(std::cin >> round) && std::cin.eof()) return 0;
		runProcess(round);
	}
}

bool runProcess(long round) {
	using namespace std;

	double tmp = 0;
	vector<double> storedNumbers;
	double average = 0.0;
	double standardDeviation = 0.0;

	for (unsigned int i = 0; i < round; i++) {
		cin >> tmp;
		average += tmp;
		storedNumbers.push_back(tmp);
	}

	average = computeAverage(average, round);
	standardDeviation = computeStandardDeviation(storedNumbers, average, round);

	cout << "Average:" << average << '\t' 
		<< "Standard deviation:"  << standardDeviation << endl;

	return true;
}

double computeAverage(double average, long round) {
	return average / round;
}

double computeStandardDeviation(std::vector<double> storedNumbers, double average, long round) {
	double standardDeviation = 0.0;
	for (unsigned int i = 0; i < storedNumbers.size(); i++) {
		standardDeviation += pow(storedNumbers[i] - average, 2);
	}
	return sqrt(standardDeviation / round);
}