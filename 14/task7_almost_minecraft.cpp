#include <iostream>

static constexpr int sizeField = 5;

void printMatrix (int matrix[][sizeField])
{
    for (int i = 0; i < sizeField; ++i) {
        for (int j = 0; j < sizeField; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
}

bool inputMatrix (int matrix[][sizeField][10])
{
    for (int i = 0; i < sizeField; ++i) {
        for (int j = 0; j < sizeField; ++j) {
            int height;
            std::cin >> height;
            if (height < 0 || height > 9)
                return false;
            for (int k = 0; k <= height; ++k)
                matrix[i][j][k] = 1;
            for (int k = height + 1; k < 10; ++k)
                matrix[i][j][k] = 0;
        }
    }
    return true;
}

void getMatrixSlice (int matrixIn[][sizeField][10], int matrixOut[][sizeField], int slice)
{
    for (int i = 0; i < sizeField; ++i)
        for (int j = 0; j < sizeField; ++j)
            matrixOut[i][j] = (matrixIn[i][j][slice]) ? 1 : 0;
}

int main ()
{
    int world[sizeField][sizeField][10];
    int matrixOfSlice[sizeField][sizeField];

    std::cout << "input matrix of heights (5x5):" << std::endl;
    if (!inputMatrix (world)) {
        std::cout << "incorrect value. Ending" << std::endl;
        return 0;
    }

    std::cout << "input slice:" << std::endl;
    int slice;
    std::cin >> slice;

    if (slice < 0 || slice > 9) {
        std::cout << "incorrect value. Ending" << std::endl;
        return 0;
    }
    getMatrixSlice (world, matrixOfSlice, slice);
    printMatrix (matrixOfSlice);

    return 0;
}
