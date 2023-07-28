#include "cpu.h"

#include <iostream>

void compute (const int* const numbers, int size = 8)
{
    int result = 0;
    for (int i = 0; i < size; ++i)
        result += numbers[i];
    std::cout << result << std::endl;
}
