#include <iostream>

bool runProcess();

int main() {
	while (true) {
		if (runProcess()) continue;
		return 0;
	}
}

bool runProcess() {
	using namespace std;

	unsigned long long s = 0;
	unsigned long long m = 0;
	unsigned long long h = 0;

	if (!(cin >> s) && cin.eof()) return false;
	
	m = s / 60;
	h = m / 60;
	s %= 60;
	m %= 60;

	printf("%lld hours %lld minutes and %lld seconds\n", h, m, s);

	return true;
}