#include <iostream>
#include <vector>
#include <string>
#include <set>

class NumberGame {
private:
	int number = 0;
	std::string loadFile = "";
	std::vector<unsigned int> S;
	std::vector<unsigned int> A;
	std::vector<unsigned int> validNumbers;
	std::set<unsigned int> C;

public:
	void SetInput(int num);
	void ProcessInput();
	void GetAllNumber(const std::vector<unsigned int> A, std::set<unsigned int>& C, int index, int currentNumber);
	void SetFileName(std::string file);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
	void test();
};