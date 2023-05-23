#include <iostream>
#include <cstring>

bool findStrInStr (const char *str1, const char *str2)
{
    if (strstr (str1, str2) == NULL)
        return false;
    return true;
}

int main ()
{
    std::cout << "Input 2 strings" << std::endl;
    char s1[100], s2[100];
    std::cin.getline (s1, 100);
    std::cin.getline (s2, 100);
    findStrInStr (s1, s2) ? std::cout << "true" : std::cout << "false";
    std::cout << std::endl;

    return 0;
}
