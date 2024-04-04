#include <iostream>
#include <string>
using namespace std;

int main() {
	double n, r, guess, old_guess;
	while (true) {
		if (!(cin >> n) && cin.eof()) return 0;
		old_guess = n + 1;
		guess = n / 2;
		while (true) {
			r = n / (guess);
			guess = (guess + r) / 2;
			if (old_guess - guess < 0.01) {
				printf("%.2f\n", guess);
				break;
			}
			old_guess = guess;
		}
	}
}