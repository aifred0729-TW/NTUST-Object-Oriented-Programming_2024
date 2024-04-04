#include <iostream>
#include <vector>
#include <fstream>

void readFile(std::vector<std::string>& names, std::vector<int>& numbers);
void getHighScores(std::vector<std::string>& names, std::vector<int>& numbers);
void runBubbleSort(std::vector<std::string>& names, std::vector<int>& numbers);

int main() {
	using namespace std;

	vector<string> names;
	vector<int> numbers;

	readFile(names, numbers);
	getHighScores(names, numbers);
	return 0;
}

void readFile(std::vector<std::string>& names, std::vector<int>& numbers) {
	using namespace std;

	fstream fp("scores.txt");
	string tmpName = "";
	int tmpNumber = 0;

	while (fp >> tmpName) {
		fp >> tmpNumber;
		names.push_back(tmpName);
		numbers.push_back(tmpNumber);
	}
	return;
}

void getHighScores(std::vector<std::string>& names, std::vector<int>& numbers) {
	using namespace std;

	runBubbleSort(names, numbers);
	
	for (unsigned int i = 0; i < names.size(); i++) {
		cout << names[i] << endl;
		cout << numbers[i] << endl;
	}
	return;
}

void runBubbleSort(std::vector<std::string>& names, std::vector<int> &numbers) {
	using namespace std;

	string tmpName = "";
	int tmpNumber = 0;

	for (unsigned int i = names.size()-1; i > 0; i--) {
		for (unsigned int j = 0; j < i; j++) {
			if (numbers[j] < numbers[j + 1]) {
				tmpName = names[j];
				tmpNumber = numbers[j];
				names[j] = names[j + 1];
				numbers[j] = numbers[j + 1];
				names[j + 1] = tmpName;
				numbers[j + 1] = tmpNumber;
			}
		}
	}
	return;
}