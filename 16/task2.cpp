#include <iostream>
#include <cmath>

int main ()
{
    std::string integer, fract;
    std::cout << "Enter the integer part of the number" << std::endl;
    std::cin >> integer;
    std::cout << "Enter the fractional part of the number" << std::endl;
    std::cin >> fract;

    std::cout << "Result: " << std::stod (integer) + std::stod (fract) / std::pow (10, fract.size ()) << std::endl;

    return 0;
}
