#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:
    //Constructor
    Matrix(vector<vector<int>> values) {
        matrix = values;
        rows = matrix.size();
        cols = matrix[0].size();
    }

    // Matrix functions (order of operations)
    // transpose - mxn -> nxm
    Matrix transpose() {
        vector<vector<int>> result(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[j][i] = matrix[i][j];
            }
        }

        return Matrix(result);
    }

    // scale - A -> cA
    Matrix scale(int scalar) {
        vector<vector<int>> result = matrix;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix[i][j] * scalar;
            }
        }

        return Matrix(result);
    }

    // mult - mxn * mxn -> m1xn2 if n1 = m2
    Matrix mult(const Matrix& matrix2) {
        vector<vector<int>> result(rows, vector<int>(matrix2.cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < matrix2.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result[i][j] += matrix[i][k] * matrix2.matrix[k][j];
                }
            }
        }

        return Matrix(result);
    }

    // add - add same (row, col) val together
    Matrix add(const Matrix& matrix2) {
        vector<vector<int>> result = matrix;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] += matrix2.matrix[i][j];
            }
        }

        return Matrix(result);
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    vector<vector<int>> matrix;
    int rows;
    int cols;
};

int main() {
    Matrix A({{6, 4}, {8, 3}});
    Matrix B({{1, 2, 3}, {4, 5, 6}});
    Matrix C({{2, 4, 6}, {1, 3, 5}});
    Matrix D = A.add(B.scale(3).mult(C.transpose())); // D = A + B * C^T
    D.print();

    return 0;
}