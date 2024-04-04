#include <iostream>
using namespace std;

// 俊漳那胖子想害我==

int main() {
	unsigned long long h, m, s;
	while (true) {
		h = 0; m = 0; s = 0;
		if (!(cin >> s) && cin.eof()) return 0;
		m = s / 60;
		h = m / 60;
		s %= 60;
		m %= 60;
		printf("%lld hours %d minutes and %d seconds\n", h, m, s);
	}
}