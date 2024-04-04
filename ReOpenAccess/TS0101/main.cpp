#include <iostream>
#include <iomanip>

bool runProcess();

int main() {
	while (true) {
		if (runProcess()) continue;
		return 0;
	}
}

bool runProcess() {
	using namespace std;

	double n = 0.0;
	if (!(cin >> n) && cin.eof()) return false;
	double guess = n / 2;
	double r = 0.0;
	
	while (true) {
		if (guess - sqrt(n) < 0.01) break;
		r = n / guess;
		guess = (guess + r) / 2;
	}

	cout << fixed << setprecision(2) << guess << endl;

	return true;
}