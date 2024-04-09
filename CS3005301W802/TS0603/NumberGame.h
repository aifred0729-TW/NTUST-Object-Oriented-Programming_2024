#include <iostream>
#include <vector>
#include <string>

class NumberGame {
private:
	int number = 0;
	std::string loadFile = "";
	std::vector<int> S;
	std::vector<int> A;
public:
	void SetInput(int num);
	void ProcessInput();
	void SetFileName(std::string file);
};