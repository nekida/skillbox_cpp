#include <iostream>

int main ()
{
    int numbers[15] = { 114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118 };
    int min, sum1, sum2;
    sum1 = sum2 = 0;
    min = INT_MAX;
    for (int i = 0; i < 15; ++i) {
        if (min > numbers[i])
            min = numbers[i];
        sum1 += numbers[i];
    }

    for (int i = 0; i < 14; ++i)
        sum2 += min + i;

    std::cout << sum1 - sum2 << std::endl;

    return 0;
}
