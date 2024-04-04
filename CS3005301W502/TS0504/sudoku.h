#include <iostream>
#include <vector>

class Sudoku {
    private:
    std::vector<std::vector<int>> map;

    public:
    Sudoku() {
        map.resize(9);
    }

    void getElement(unsigned int row, int element);
    bool scanXY();
    bool scanArea();
};