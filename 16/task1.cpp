#include <iostream>

int main ()
{
    double speed = 0.0;
    do {
        std::cout << "Input delta of speed: ";
        double delta;
        std::cin >> delta;
        speed += delta;
        char speedStr[20];
        char units[] = " km/h";
        int n = std::sprintf (speedStr, "%.1f", speed);
        std::sprintf (&speedStr[n], "%s", units);
        std::cout << "Speed equal " << speedStr << std::endl;
    } while (speed > 0.01 && speed < 150.01);

    return 0;
}
