#include <iostream>
#include <string>
#include <vector>

class Canva {
private:
	int row = 0;
	int col = 0;
	std::vector<std::vector<char>> map;

	void initialization() {
		map.resize(row);
		for (unsigned int i = 0; i < row; i++) {
			for (unsigned int j = 0; j < col; j++) {
				map[i].push_back('*');
			}
		}
		return;
	}

	void display() {
		for (unsigned int i = 0; i < row; i++) {
			for (unsigned int j = 0; j < col; j++) {
				std::cout << map[i][j];
			}
			std::cout << std::endl;
		}
		return;
	}

public:
	Canva(int r, int c) {
		row = r;
		col = c;
		initialization();
	}

	void drawSquare(int w, int x, int y) {
		using namespace std;

		for (unsigned int r = x; r < w; r++) {
			for (unsigned int c = y; c < w; c++) {
				map[r][c] = 'X';
			}
		}
		display();
		return;
	}

	void drawLine(int x1, int x2, int y1, int y2) {
		using namespace std;

		if (x1 == x2) {
			for (unsigned int i = min(y1, y2); i < max(y1, y2); i++) {
				map[x1][i] = 'X';
			}
		}
		else if (y1 == y2) {
			for (unsigned int i = min(x1, x2); i < max(x1, x2); i++) {
				map[i][x1] = 'X';
			}
		}
		else {
			if (y1 < y2) {

			}
			else if (y1 > y2) {

			}
		}
	}
};