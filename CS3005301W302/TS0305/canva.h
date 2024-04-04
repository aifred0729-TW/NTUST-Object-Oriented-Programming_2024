#pragma once
#include <iostream>
#include <string>
#include <vector>

class Canva {
    public:
    int row    = 0;
    int column = 0;

    std::vector<std::vector<char>> paper;

    void initialPaper() {
        unsigned int i = 0;
        unsigned int j = 0;

        paper.resize(row);

        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                paper[i].push_back('*');
            }
        }
        return;
    }

    void displayPaper() {
        using namespace std;

        unsigned int i = 0;
        unsigned int j = 0;

        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                cout << paper[i][j];
            }
            cout << endl;
        }
        return;
    }

    bool detectOutOfRange(int opcode, int w, int x, int y) {
        // 0 = LU, 1 = LD, 2 = RU, 3 = RD
        switch (opcode) {
            case 0:
                if (x - w + 1 < 0 || y - w + 1 < 0)
                    return true;

                return false;
            case 1:
                if (x - w + 1 < 0 || y + w - 1 > row)
                    return true;

                return false;
            case 2:
                if (x + w > column || y - w + 1 < 0)
                    return true;

                return false;
            case 3:
                if (x + w > column || y + w > row)
                    return true;

                return false;
        }
    }

    void drawSquare(int w, int x, int y) {
        using namespace std;

        unsigned int pointerX = 0;
        unsigned int pointerY = 0;

        if (x + w > column || y + w > row) {
            cout << "Out of range." << endl;
            return;
        }

        for (pointerY = y; pointerY < y + w; pointerY++) {
            for (pointerX = x; pointerX < x + w; pointerX++) {
                paper[pointerY][pointerX] = 'X';
            }
        }

        this->displayPaper();
        return;
    }

    void drawTriangle(int w, int x, int y, std::string opcodeT) {
        using namespace std;

        int pointerX = 0;
        int pointerY = 0;

        if (opcodeT == "LU") {
            if (this->detectOutOfRange(0, w, x, y)) {
                cout << "Out of range." << endl;
                return;
            }
            for (pointerY = y; pointerY > y - w; pointerY--) {
                for (pointerX = x - w + 1 + (y - pointerY); pointerX < x + 1; pointerX++) {
                    paper[pointerY][pointerX] = 'X';
                }
            }
        } else if (opcodeT == "LD") {
            if (this->detectOutOfRange(1, w, x, y)) {
                cout << "Out of range." << endl;
                return;
            }
            for (pointerY = y; pointerY < y + w; pointerY++) {
                for (pointerX = x - w + 1 + (pointerY - y); pointerX < x + 1; pointerX++) {
                    paper[pointerY][pointerX] = 'X';
                }
            }
        } else if (opcodeT == "RU") {
            if (this->detectOutOfRange(2, w, x, y)) {
                cout << "Out of range." << endl << endl;
                return;
            }
            for (pointerY = y; pointerY > y - w; pointerY--) {
                for (pointerX = x; pointerX < x + w - (y - pointerY); pointerX++) {
                    paper[pointerY][pointerX] = 'X';
                }
            }
        } else if (opcodeT == "RD") {
            if (this->detectOutOfRange(3, w, x, y)) {
                cout << "Out of range." << endl << endl;
                return;
            }
            for (pointerY = y; pointerY < y + w; pointerY++) {
                for (pointerX = x; pointerX < x + w - (pointerY - y); pointerX++) {
                    paper[pointerY][pointerX] = 'X';
                }
            }
        }

        this->displayPaper();
        return;
    }

    void drawLine(int x1, int y1, int x2, int y2) {
        using namespace std;

        unsigned int pointerX = 0;
        unsigned int pointerY = 0;

        if (x1 > column || y1 > row || x2 > column || y2 > row) {
            cout << "Out of range." << endl;
            return;
        }

        if (x1 == x2) {
            for (pointerY = min(y1, y2); pointerY < max(y1, y2); pointerY++) {
                paper[pointerY][x1] = 'X';
            }
        } else if (y1 == y2) {
            for (pointerX = min(x1, x2); pointerX < max(x1, x2); pointerX++) {
                paper[y1][pointerX] = 'X';
            }
        } else {
            if (y1 < y2) {
                pointerX = min(x1, x2);
                for (pointerY = max(y1, y2); pointerY > min(y1, y2); pointerY--) {
                    paper[pointerY][pointerX] = 'X';
                    pointerX++;
                }
            } else {
                pointerX = min(x1, x2);
                for (pointerY = min(y1, y2); pointerY < max(y1, y2); pointerY++) {
                    paper[pointerY][pointerX] = 'X';
                    pointerX++;
                }
            }
        }

        this->displayPaper();
        return;
    }
};