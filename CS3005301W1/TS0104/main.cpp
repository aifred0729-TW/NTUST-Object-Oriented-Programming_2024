#include <iostream>
#include <string>
using namespace std;

int main() {
	string buffer;
	while (true) {
		if (!(cin >> buffer) && cin.eof()) return 0;
		if (buffer.size() < 10) {
			for (int i = 0; i < 10 - buffer.size(); i++) {
				cout << ' ';
			}
			cout << buffer << endl;
		}
		else {
			cout << buffer << endl;
		}
	}
}