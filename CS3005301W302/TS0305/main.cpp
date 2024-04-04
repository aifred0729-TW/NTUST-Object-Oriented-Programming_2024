#include <iostream>
#include <string>
#include <vector>

#include "canva.h"

void runProcess(int row, int column);

int main() {
    using namespace std;

    int row    = 0;
    int column = 0;

    cin >> column >> row;

    runProcess(row, column);
    return 0;
}

void runProcess(int row, int column) {
    using namespace std;

    Canva instancedCanva;
    instancedCanva.row    = row;
    instancedCanva.column = column;
    instancedCanva.initialPaper();

    while (true) {
        string opcode = "";
        cin >> opcode;

        if (opcode == "S") {
            int w = 0;
            int x = 0;
            int y = 0;

            cin >> w >> x >> y;
            instancedCanva.drawSquare(w, x, y);

        } else if (opcode == "T") {
            int    w       = 0;
            int    x       = 0;
            int    y       = 0;
            string opcodeT = "";

            cin >> w >> x >> y >> opcodeT;
            instancedCanva.drawTriangle(w, x, y, opcodeT);

        } else if (opcode == "L") {
            int x1 = 0;
            int y1 = 0;
            int x2 = 0;
            int y2 = 0;
            
            cin >> x1 >> y1 >> x2 >> y2;
            instancedCanva.drawLine(x1, y1, x2, y2);

        } else {
            return;
        }
        cout << endl;
    }
}