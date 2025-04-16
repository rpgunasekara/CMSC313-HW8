#include <stdio.h>

#define ROW2 2
#define ROW3 3
#define COL2 2
#define COL3 3

// Matrix functions (order of operations)
// transpose - mxn -> nxm
void transpose(int result[ROW3][COL2], int mat[ROW2][COL3]) {
    for (int i = 0; i < ROW2; i++) {
        for (int j = 0; j < COL3; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// scale - A -> cA
void scale(int mat[ROW2][COL3], int scalar) {
    for (int i = 0; i < ROW2; i++) {
        for (int j = 0; j < COL3; j++) {
            mat[i][j] *= scalar;
        }
    }
}

// mult - mxn * mxn -> m1xn2 if n1 = m2
void mult(int result[ROW2][COL2], int mat1[ROW2][COL3], int mat2[ROW3][COL2]) {
    for (int i = 0; i < ROW2; i++) {
        for (int j = 0; j < COL2; j++) {
            result[i][j] = 0;

            for (int k = 0; k < COL3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// add - add same (row, col) val together
void add(int result[ROW2][COL2], int mat1[ROW2][COL2], int mat2[ROW2][COL2]) {
    for (int i = 0; i < ROW2; i++) {
        for (int j = 0; j < COL2; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void print(int mat[ROW2][COL2]) {
    for (int i = 0; i < ROW2; i++) {
        for (int j = 0; j < COL2; j++) {
            printf("%d ", mat[i][j]);
        }
        
        printf("\n");
    }
}

int main() {
    int A[ROW2][COL2] = {{6, 4}, {8, 3}};
    int B[ROW2][COL3] = {{1, 2, 3}, {4, 5, 6}};
    int C[ROW2][COL3] = {{2, 4, 6}, {1, 3, 5}};
    
    int Ctranspose[ROW3][COL2];
    transpose(Ctranspose, C);
    scale(B, 3);
    int BCmult[ROW2][COL2];
    mult(BCmult, B, Ctranspose);
    int D[ROW2][COL2];
    add(D, A, BCmult);
    print(D);

    return 0;
}