#include <iostream>
#include <string>

void printMatrix (int matrix[][4])
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void inputMatrix (int matrix[][4])
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> matrix[i][j];
        }

    }
}

bool checkMatrices (int matrixOne[][4], int matrixTwo[][4])
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrixOne[i][j] != matrixTwo[i][j])
                return false;
        }
    }
    return true;
}

void toDiagonalMatrix (int matrix[][4])
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j)
                matrix[i][j] = 0;
        }
    }
}

int main ()
{
    int A[4][4], B[4][4];
    std::cout << "Input first matrix" << std::endl;
    inputMatrix (A);
    std::cout << "Input second matrix" << std::endl;
    inputMatrix (B);
    std::cout << std::endl;
    std::cout << "Matrix A:" << std::endl;
    printMatrix (A);
    std::cout << std::endl;
    std::cout << "Matrix B:" << std::endl;
    printMatrix (B);
    if (!checkMatrices (A, B)) {
        std::cout << std::endl;
        std::cout << "Matrices are not equal. Ending" << std::endl;
        return 0;
    }
    std::cout << std::endl;
    std::cout << "Diagonal Matrix:" << std::endl;
    toDiagonalMatrix (B);
    printMatrix (B);

    return 0;
}
