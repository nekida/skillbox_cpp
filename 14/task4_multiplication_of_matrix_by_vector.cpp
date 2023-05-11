#include <iostream>
#include <string>

void printMatrix (float matrix[][4])
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
}

void inputMatrix (float matrix[][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            std::cin >> matrix[i][j];
}

void printVector (float* v)
{
    for (int i = 0; i < 4; ++i) {
        std::cout << v[i];
        std::cout << std::endl;
    }
}

void inputVector (float* v)
{
    for (int i = 0; i < 4; ++i)
        std::cin >> v[i];
}


int main ()
{
    float a[4][4], b[4], c[4];
    std::cout << "Input matrix" << std::endl;
    inputMatrix (a);
    std::cout << "Input vector" << std::endl;
    inputVector (b);
    std::cout << std::endl;
    std::cout << "You entered:" << std::endl;
    printMatrix (a);
    std::cout << std::endl;
    printVector (b);

    for (int i = 0; i < 4; ++i) {
        c[i] = 0;
        for (int j = 0; j < 4; ++j)
            c[i] += a[i][j] * b[j];
    }

    std::cout << std::endl;
    std::cout << "Result:" << std::endl;
    printVector (c);

    return 0;
}
