#include <iostream>
#include <vector>

class Memory {
private:
	// char 1, short 2, int 3, string 4
	std::vector<unsigned char> space;
	std::vector<int> locate;
	std::vector<int> type;
	int size;

public:
	Memory(int memsize) {
		size = memsize;
		space.resize(memsize);
	}

	bool runSecurityCheck(int point, int type, int strSize);
	void write(int pointer, int dataType, std::string data);
	void read(int pointer, int dataType);
};