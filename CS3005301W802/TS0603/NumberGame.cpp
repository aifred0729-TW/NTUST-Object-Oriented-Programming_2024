#include <iostream>
#include <vector>
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

	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}
	return;
}

void NumberGame::SetFileName(std::string file) {
	loadFile = file;
	return;
}

