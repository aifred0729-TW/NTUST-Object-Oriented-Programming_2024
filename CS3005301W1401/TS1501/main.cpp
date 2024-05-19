#include <iostream>
#include <set>
#include <string>
#include <fstream>

void readFile(std::string filename, std::set<std::string>& names);

int main() {
	using namespace std;

	set<string> names;
	
	readFile("name.txt", names);

	for (auto tmp : names) {
		cout << tmp << endl;
	}

	return 0;
}

void readFile(std::string filename, std::set<std::string>& names) {
	using namespace std;

	ifstream fp(filename);
	string tmp = "";

	while (getline(fp, tmp)){
		names.insert(tmp);
	}

	return;
}