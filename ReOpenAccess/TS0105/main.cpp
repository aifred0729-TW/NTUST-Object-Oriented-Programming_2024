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

	double r = 0.0;
	double volume = 0.0;
	double PI = 3.14159265358979323846;

	if (!(cin >> r) && cin.eof()) return false;
	
	volume = (double)4/3*PI*(double)pow(r, 3);

	cout << fixed << setprecision(6) << volume << endl;

	return true;
}