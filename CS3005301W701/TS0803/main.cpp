#include <iostream>
#include <vector>
#include "memory.h"
#include <string>

void runProcess(Memory mem);
bool runSecurityCheckInterface(Memory mem, int point, int dataType, int dataSize);

int main() {
	using namespace std;

	int memsize = 0;
	cin >> memsize;
	Memory mem(memsize);

	int count = 0;
	cin >> count;

	for (unsigned int i = 0; i < count; i++) {
		runProcess(mem);
	}
	return 0;
}

void runProcess(Memory mem) {
	using namespace std;

	string opcode = "";
	string typeOpcode = "";

	int pointer = 0;
	int dataType = 0;
	string data = "";

	cin >> opcode >> pointer >> typeOpcode;

	dataType = getDataType(typeOpcode);

	if (opcode == "Set") {
		getline(cin >> ws, data);
		if (!runSecurityCheckInterface(mem, pointer, dataType, data.size())) return;

	}
	else if (opcode == "Get") {
		if (!runSecurityCheckInterface(mem, pointer, dataType, 0)) return;
	}
	return;
}

int getDataType(std::string dataType) {
	if (dataType == "char") return 1;
	else if (dataType == "short") return 2;
	else if (dataType == "int") return 3;
	else if (dataType == "String") return 4;
	return 0;
}

bool runSecurityCheckInterface(Memory mem, int point, int dataType, int dataSize) {
	using namespace std;
	if (mem.runSecurityCheck(point, dataType, dataSize)) {
		cout << "Violation Access." << endl;
		return false;
	}
	return true;
}