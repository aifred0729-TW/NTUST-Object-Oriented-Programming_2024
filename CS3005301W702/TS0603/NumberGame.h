#include <iostream>
#include <vector>
#include <string>

class NumberGame {
private:
	int inputNumber = 0;
	std::string fileName = "";
	std::vector<int> splitNumbers;
	std::vector<int> loadNumbers;
public:
	void SetInput(int input);
	void ProcessInput();
	void SetFileName(std::string file);
	void LoadNumberList();
	void PrintAllValid();
};