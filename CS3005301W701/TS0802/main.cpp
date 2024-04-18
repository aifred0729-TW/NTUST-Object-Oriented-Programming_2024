#include <iostream>
#include <vector>

bool runProcess();
void getMatrixElement(std::vector<std::vector<int>>& matrix, int row, int col);

int main() {
    while (true) {
        if (runProcess())
            continue;
        return 0;
    }
}

bool runProcess() {
    using namespace std;

    vector<vector<int>> A;
    vector<vector<int>> B;
    vector<vector<int>> C;

    int Arow = 0;
    int Acol = 0;
    int Brow = 0;
    int Bcol = 0;

    if (!(cin >> Arow) && cin.eof())
        return false;

    cin >> Acol >> Brow >> Bcol;

    A.resize(Arow);
    B.resize(Brow);
    C.resize(Arow);

    getMatrixElement(A, Arow, Acol);
    getMatrixElement(B, Brow, Bcol);

    if (Acol != Brow) {
        cout << "Matrix multiplication failed." << endl;
        return true;
    }

    int tmp = 0;

    for (unsigned int i = 0; i < Arow; i++) {
        for (unsigned int j = 0; j < Bcol; j++) {
            tmp = 0;
            for (unsigned int a = 0; a < Acol; a++) {
                tmp += A[i][a] * B[a][j];
            }
            C[i].push_back(tmp);
        }
    }

    for (unsigned int i = 0; i < C.size(); i++) {
        for (unsigned int j = 0; j < C[i].size() - 1; j++) {
            cout << C[i][j] << ' ';
        }
        cout << C[i][C[i].size() - 1] << endl;
    }
    return true;
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