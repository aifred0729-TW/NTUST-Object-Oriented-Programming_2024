#include <iostream>
#include <vector>
#include <fstream>
#include "NumberGame.h"

void NumberGame::SetInput(int num) {
	number = num;
	return;
}

void NumberGame::ProcessInput() {
	using namespace std;

	int tmp = number;
	while (tmp != 0) {
		A.push_back(tmp % 10);
		tmp /= 10;
	}

	GetAllNumber(A, C, 0, 1);

	for (const auto &s : C) {
		validNumbers.push_back(s);
	}
	return;
}

void NumberGame::GetAllNumber(const std::vector<unsigned int> A, std::set<unsigned int> &C, int index, int currentNumber) {
	if (index == A.size()) {
		C.insert(currentNumber);
		return;
	}
	GetAllNumber(A, C, index + 1, currentNumber);
	GetAllNumber(A, C, index + 1, currentNumber * A[index]);
	return;
}

void NumberGame::SetFileName(std::string file) {
	loadFile = file;
	return;
}

void NumberGame::LoadNumberList() {
	using namespace std;
	ifstream fp(loadFile);
	unsigned int loadInt = 0;
	while (fp >> loadInt) {
		S.push_back(loadInt);
	}
	return;
}

void NumberGame::PrintAllValid() {
	using namespace std;

	auto oneExist = find(A.begin(), A.end(), 1);
	if (!(oneExist != A.end())) validNumbers.erase(validNumbers.begin());

	for (unsigned int loadNumber : S) {
		auto isFind = find(validNumbers.begin(), validNumbers.end(), loadNumber);
		if (isFind != validNumbers.end()) {
			cout << loadNumber << endl;
		}
	}

	return;
}

void NumberGame::Reset() {
	number = 0;
	loadFile = "";
	validNumbers.clear();
	S.clear();
	A.clear();
	C = {};
	return;
}

void NumberGame::test() {
	for (unsigned int i = 0; i < validNumbers.size(); i++) {
		std::cout << validNumbers[i] << std::endl;
	}
}