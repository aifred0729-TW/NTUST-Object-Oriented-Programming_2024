#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main() {
	double r, result;
	double PI = 3.14159265358979323846;
	while (true) {
		if (!(cin >> r) && cin.eof()) return 0;
		result = 4.0 / 3.0 * (PI * pow(r, 3));
		cout << fixed << setprecision(6) << result << endl;
	}
}