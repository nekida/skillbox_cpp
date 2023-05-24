#include <iostream>

int getNumJumpVariants (int step)
{
    if (step < 0)
        return 0;
    else if (step == 0)
        return 1;
    else
        return getNumJumpVariants (step - 3) + getNumJumpVariants (step - 2) + getNumJumpVariants (step - 1);
}

int main ()
{
    std::cout << "Input num step" << std::endl;
    int n;
    std::cin >> n;
    std::cout << getNumJumpVariants (n) << std::endl;
    return 0;
}
