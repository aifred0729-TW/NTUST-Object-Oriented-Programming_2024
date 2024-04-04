#include <iostream>
#include <string>

bool runProcess();

int main() {
	while (true) {
		if (runProcess()) continue;
		return 0;
	}
}

bool runProcess() {
	using namespace std;
	
	string number = "";

	if (!(cin >> number) && cin.eof()) return false;

	if (number.size() < 10) {
		for (unsigned int i = 0; i < 10 - number.size(); i++) {
			cout << ' ';
		}
	}

	cout << number << endl;

	return true;
}