#include <iostream>
#include <vector>
#include "memory.h"
#include <string>

int main() {
	using namespace std;

	int memsize = 0;
	int count = 0;
	int point = 0;
	int saveType = 0;
	string opcode = "";
	string dataType = "";
	string data = "";

	cin >> memsize;
	Memory mem(memsize);

	cin >> count;

	for (unsigned int i = 0; i < count; i++) {
		cin >> opcode >> point >> dataType;

		saveType = sortDataType(dataType);

		if (opcode == "Set") {
			getline(cin >> ws, data);
			if (!runBordardCheck(mem, point, saveType, data.size())) continue;

		}
		else if (opcode == "Get") {
			if (!runBordardCheck(mem, point, saveType, 0)) continue;
		}

	}
}

int sortDataType(std::string dataType) {
	if (dataType == "char") return 1;
	else if (dataType == "short") return 2;
	else if (dataType == "int") return 3;
	else if (dataType == "String") return 4;
	return 0;
}

bool runBordardCheck(Memory mem, int point, int saveType, int dataSize) {
	using namespace std;
	if (!mem.runSecurityCheck(point, saveType, dataSize)) {
		cout << "Violation Access." << endl;
		return false;
	}
	return true;
}