#include <iostream>

int getNumJumpVariants (int step, int k = 3)
{
    if (step < 0)
        return 0;
    else if (step == 0)
        return 1;
    else {
        int sum = 0;
        for (int i = k; i > 0; --i)
            sum += getNumJumpVariants (step - i, k);
        return sum;
    }
}

int main ()
{
    std::cout << "Input num step and jump length" << std::endl;
    int n, k;
    std::cin >> n >> k;
    std::cout << getNumJumpVariants (n, k) << std::endl;
    return 0;
}
