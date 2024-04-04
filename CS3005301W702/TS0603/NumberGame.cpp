#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "NumberGame.h"

void NumberGame::SetInput(int input) {
	inputNumber = input;
	return;
}

void NumberGame::ProcessInput() {
	using namespace std;
	while (true) {
		splitNumbers.push_back(inputNumber % 10);
		inputNumber /= 10;
		if (inputNumber / 10 == 0) {
			splitNumbers.push_back(inputNumber % 10);
			break;
		}
	}
	return;
}

void NumberGame::SetFileName(std::string file) {
	fileName = file;
	return;
}

void NumberGame::LoadNumberList() {
	using namespace std;
	ifstream fp(fileName);
	int tmp = 0;
	while (fp >> tmp) {
		loadNumbers.push_back(tmp);
	}
	return;
}

void NumberGame::PrintAllValid() {
	using namespace std;

	for (unsigned int i = 0; i < loadNumbers.size(); i++) {
		for (unsigned int j = 0; j < splitNumbers.size(); j++) {

		}
	}
}

bool removeNumberNode(int num, int &loadNumber) {
	while (loadNumber % num != 0) {
		loadNumber /= num;
	}
}