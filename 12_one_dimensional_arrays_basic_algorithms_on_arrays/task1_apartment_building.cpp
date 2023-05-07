#include <iostream>
#include <string>

int main ()
{
    std::string residents[10];
    std::cout << "Input residents:" << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cin >> residents[i];

    std::cout << "Input number of apartament:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        int num;
        std::cin >> num;
        if (num < 1 || num > 10)
            std::cout << "You entered the wrong apartment number" << std::endl;
        else
            std::cout << residents[num - 1] << std::endl;
    }
    return 0;
}
