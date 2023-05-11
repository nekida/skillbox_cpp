#include <iostream>
#include <string>

void printMatrix (int matrix[][5])
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            std::cout << matrix[i][j] << '\t';
        std::cout << std::endl;
    }
}

int main ()
{
    int digits[5][5];
    for (int i = 0, number = 0, multiplier = 1; i < 5; ++i, multiplier *= -1, number += 5) {
        for (int j = 0; j < 5; ++j) {
            digits[i][j] = number;
            number += multiplier;
        }
        number += multiplier * -1;
    }

    std::cout << "Result:" << std::endl;
    printMatrix (digits);

    return 0;
}
