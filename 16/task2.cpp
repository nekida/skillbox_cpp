#include <iostream>
#include <string>

int main ()
{
    std::string integer, fract;
    std::cout << "Enter the integer part of the number" << std::endl;
    std::cin >> integer;
    std::cout << "Enter the fractional part of the number" << std::endl;
    std::cin >> fract;

    std::string result = integer + '.' + fract;
    std::cout << "Result: " << std::stod (result) << std::endl;

    return 0;
}
