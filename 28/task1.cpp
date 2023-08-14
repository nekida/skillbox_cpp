#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <vector>

class Swimmer {
    std::string name;
    size_t speedMPS = 0;
    size_t distance = 0;

public:
    std::string& getName() { return name; }

    size_t getSpeed() { return speedMPS; }

    void setSpeed(size_t speed) { speedMPS = speed; }

    size_t& getDistance() { return distance; }
};

void distanceUpdate ()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main ()
{
    constexpr int numSwimmers = 6;
    Swimmer swimmers[numSwimmers];
    for (size_t i = 0; i < numSwimmers; ++i) {
        std::cout << "Enter the name and speed of swimmer number " << i + 1 << std::endl;
        std::cin >> swimmers[i].getName();
        size_t speed;
        std::cin >> speed;
        swimmers[i].setSpeed(speed);
    }

    std::thread swimmersThreads[numSwimmers];
    for (size_t i = 0; i < numSwimmers; ++i)
        swimmersThreads[0] = std::thread(distanceUpdate);

    bool isAll = false;
    while (!isAll) {
        isAll = true;
        for (size_t i = 0; i < numSwimmers; ++i) {
            swimmersThreads[i].join();
            swimmers->getDistance() += swimmers->getSpeed();
            isAll &= swimmers[i].getDistance() >= 100;
        }
    }


    return 0;
}
