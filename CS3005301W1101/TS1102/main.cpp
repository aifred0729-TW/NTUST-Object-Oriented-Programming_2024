#include <iostream>
#include <vector>

void getMatrixElement(std::vector<std::vector<int>>& matrix, int row, int col);

int main() {
    using namespace std;

    int rowA = 0;
    int rowB = 0;
    int colA = 0;
    int colB = 0;

    int tmp = 0;

    vector<vector<int>> matrixA;
    vector<vector<int>> matrixB;
    vector<vector<int>> matrixC;

    while (true) {
        if (!(cin >> rowA) && cin.eof())
            break;

        cin >> colA >> rowB >> colB;

        if (colA != rowB) {
            cout << "Matrix multiplication failed." << endl;
            return 0;
        }

        matrixA.resize(rowA);
        matrixB.resize(rowB);
        matrixC.resize(rowA);

        getMatrixElement(matrixA, rowA, colA);
        getMatrixElement(matrixB, rowB, colB);

        for (unsigned int i = 0; i < rowA; i++) {
            for (unsigned int j = 0; j < colB; j++) {
                tmp = 0;
                for (unsigned int k = 0; k < colA; k++) {
                    tmp += matrixA[i][k] * matrixB[k][j];
                }
                matrixC[i].push_back(tmp);
            }
        }

        for (unsigned int i = 0; i < matrixC.size(); i++) {
            for (unsigned int j = 0; j < matrixC[i].size() - 1; j++) {
                cout << matrixC[i][j] << ' ';
            }
            cout << matrixC[i][matrixC[i].size() - 1] << endl;
        }
    }

    return 0;
}

void getMatrixElement(std::vector<std::vector<int>>& matrix, int row, int col) {
    int element = 0;
    for (unsigned int i = 0; i < row; i++) {
        for (unsigned int j = 0; j < col; j++) {
            std::cin >> element;
            matrix[i].push_back(element);
        }
    }
    return;
}