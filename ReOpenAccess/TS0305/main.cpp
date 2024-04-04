#include <iostream>
#include <string>
#include <vector>
#include "canva.h"

bool runProcess();

int main() {
	while (true) {
		if (runProcess()) continue;
		return 0;
	}
}

bool runProcess() {
	using namespace std;

	int row = 0;
	int col = 0;
	string opcode = "";

	if (!(cin >> row) && cin.eof()) return false;
	cin >> col;

	Canva instancedCanva(row, col);

	while (true) {
		cin >> opcode;
		if (opcode == "S") {
			int w = 0;
			int x = 0;
			int y = 0;
			cin >> w >> x >> y;
			instancedCanva.drawSquare(w, x, y);
		}
		else if (opcode == "T") {
			int w = 0;
			int x = 0;
			int y = 0;
			string opcodeT = "";
			cin >> w >> x >> y >> opcodeT;

		}
		else if (opcode == "L") {
			int x1 = 0;
			int x2 = 0;
			int y1 = 0;
			int y2 = 0;
			cin >> x1 >> y1 >> x2 >> y2;

		}
		else {
			break;
		}
		cout << endl;
	}

	return true;
}