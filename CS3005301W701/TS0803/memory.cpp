#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "memory.h"

bool Memory::runSecurityCheck(int point, int dataType, int strSize) {
	if (point > size) return true;
	switch (dataType) {
	case 1:
		if (point +1> size) return true;
		break;
	case 2:
		if (point + 2 > size) return true;
		break;
	case 3:
		if (point + 4 > size) return true;
		break;
	case 4:
		if (point + strSize > size) return true;
		break;
	}
	return false;
}

void Memory::write(int pointer, int dataType, std::string origin_data) {
	using namespace std;

	stringstream ss("");
	unsigned int data = 0;
	unsigned int tmp = 0;

	switch (dataType) {
	case 1:
		space[pointer] = stoi(origin_data);
		break;
	case 2:
		ss << origin_data;
		ss >> data;
		while (true) {
			if (data == 0) break;
			tmp = data % 256;
			data /= 256;
			space[pointer] = tmp;
			pointer++;
		}
		break;
	case 3:
		ss << origin_data;
		ss >> data;
		while (true) {
			if (data == 0) break;
			if (pointer == size) break;
			tmp = data % 256;
			data /= 256;
			space[pointer] = tmp;
			pointer++;
		}
		break;
	case 4:
		for (unsigned int i = 0; i < origin_data.size(); i++) {
			space[pointer+i] = origin_data[i];
		}
		break;
	}
	return;
}

void Memory::read(int pointer, int dataType) {
	using namespace std;

	int powCount = 0;
	unsigned int resultInt = 0;
	string resultStr = "";
	bool display = false;

	switch (dataType) {
	case 1:
		if (pointer == size) break;
		resultInt = space[pointer];
		if (resultInt != 0)	cout << resultInt << endl;
		break;
	case 2:
		for (unsigned int i = 0; i < 2; i++) {
			if (pointer == size) {
				display = false;
				break;
			}
			resultInt += space[pointer] * pow(256, powCount);
			powCount++;
		}
		if (resultInt != 0)	cout << resultInt << endl;
		break;
	case 3:
		for (unsigned int i = 0; i < 4; i++) {
			if (pointer == size) {
				display = false;
				break;
			}
			resultInt += space[pointer] * pow(256, powCount);
			powCount++;
		}
		if (resultInt != 0 && display) cout << resultInt << endl;
		break;
	case 4:
		while (true) {
			if (pointer + 1 > size) break;
			if (space[pointer] == '\0') break;
			resultStr += space[pointer];
			pointer++;
		}
		cout << resultStr << endl;
		break;
	}
	return;
}