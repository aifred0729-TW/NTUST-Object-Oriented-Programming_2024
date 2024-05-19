#include "Database.h"

int main() {
	using namespace std;

	string opcode = "";

	while (cin >> opcode) {
		cout << opcode << endl;
		runProcess(opcode);
	}

	return 0;
}

void runProcess(std::string opcode) {
	using namespace std;
	
	int mode = 0;


	if (opcode == "Insert") {
		
	}
	else if (opcode == "Delete") {

	}
	else if (opcode == "Find") {

	}
	else if (opcode == "Sort") {

	}

	return;
}

void runModule(int mode) {
	using namespace std;

	switch (mode) {
	case 0:
		cout << "Unknown Command." << endl;
		break;
	case 1:
		cout << "Incomplete Command." << endl;
		break;
	}
}