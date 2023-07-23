#include <iostream>

#define WINTER

int main ()
{
#if defined(SPRING)
    std::cout << "Spring" << std::endl;
#elif defined(SUMMER)
    std::cout << "Summer" << std::endl;
#elif defined(AUTUMN)
    std::cout << "Autumn" << std::endl;
#elif defined(WINTER)
    std::cout << "Winter" << std::endl;
#endif

    return 0;
}
