#include <iostream>
#include <vector>
#include "memory.h"
#include <string>

void runProcess(int memsize, int count);
int getDataType(std::string dataType);
void runSecurityCheckInterface(Memory &mem, int point, int dataType, int dataSize);

int main() {
	using namespace std;

	int memsize = 0;
	int count = 0;

	cin >> memsize;
	cin >> count;


	runProcess(memsize, count);

	return 0;
}

void runProcess(int memsize, int count) {
	using namespace std;

	Memory mem(memsize);

	string opcode = "";
	string typeOpcode = "";

	int pointer = 0;
	int dataType = 0;
	string data = "";

	for (unsigned int i = 0; i < count; i++) {
		cin >> opcode >> pointer >> typeOpcode;

		dataType = getDataType(typeOpcode);

		if (opcode == "Set") {
			getline(cin >> ws, data);
			runSecurityCheckInterface(mem, pointer, dataType, data.size());
			mem.write(pointer, dataType, data);
		}
		else if (opcode == "Get") {
			runSecurityCheckInterface(mem, pointer, dataType, 0);
			mem.read(pointer, dataType);
		}
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

void runSecurityCheckInterface(Memory &mem, int point, int dataType, int dataSize) {
	using namespace std;
	if (mem.runSecurityCheck(point, dataType, dataSize)) {
		cout << "Violation Access." << endl;
	}
	return;
}