#include <iostream>
#include <vector>

class Shisensho {
    private:
    int row    = 0;
    int column = 0;

    std::vector<std::vector<int>> map;

    public:
    Shisensho(int r, int c) {
        row    = r;
        column = c;
    }
    void initializeMap();
    void pushByRow(int row, int value);
    bool checkIsPair(int srcRow, int srcCol, int dstRow, int dstCol);


    void test() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                std::cout << map[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};