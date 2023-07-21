#include <iostream>
#include <string>
#include <map>

#define CONCAT(a) a ## DAY

#define MONDAY "Monday"
#define TUESDAY "Tuesday"
#define WEDNESDAY "Wednesday"
#define THURSDAY "Thursday"
#define FRIDAY "Friday"
#define SATURDAY "Saturday"
#define SUNDAY "Sunday"

#define PRINT_NAME_DAY(name) \
    switch (name) { \
        case (1): std::cout << CONCAT(MON) << std::endl; break; \
        case (2): std::cout << CONCAT(TUES) << std::endl; break; \
        case (3): std::cout << CONCAT(WEDNES) << std::endl; break; \
        case (4): std::cout << CONCAT(THURS) << std::endl; break; \
        case (5): std::cout << CONCAT(FRI) << std::endl; break; \
        case (6): std::cout << CONCAT(SATUR) << std::endl; break; \
        case (7): std::cout << CONCAT(SUN) << std::endl; break; \
        default: std::cout << "There is no day of the week with this number" << std::endl; \
    }

int main ()
{
    std::cout << "Input the number day of week (1..7)" << std::endl;
    int numDay;
    std::cin >> numDay;
    PRINT_NAME_DAY(numDay);

    return 0;
}
