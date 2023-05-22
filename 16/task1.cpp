#include <iostream>

int main ()
{
    std::cout << "Input delta of speed: ";
    double delta;
    std::cin >> delta;
    double speed = 0.0;
    do {
        speed += delta;
        char speedStr[20];
        char units[] = " km/h";
        int n = std::sprintf (speedStr, "%.1f", speed);
        std::sprintf (&speedStr[n], "%s", units);
        std::cout << "Speed equal " << speedStr << std::endl;
        std::cout << "Input delta of speed: ";
        std::cin >> delta;
    } while (speed > 0.01 && speed < 150.01 && delta < 150);

    return 0;
}
