#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <vector>
#include <mutex>

class Swimmer {
    std::string name;

    size_t speedMPS = 0;

    size_t distance = 0;

public:
    std::string& getName() { return name; }

    size_t getSpeed() { return speedMPS; }

    void setSpeed(size_t speed) { speedMPS = speed; }

    size_t& getDistance() { return distance; }

    bool isFinished = false;

    size_t time = 0;
};

std::mutex stdio_access;

void distanceUpdate (std::string name, size_t distance)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    stdio_access.lock();
    std::cout << name;
    distance < 100 ? std::cout << " swimming " << distance << " meters" : std::cout << " finished";
    std::cout << std::endl;
    stdio_access.unlock();
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

    bool isAll = false;
    while(!isAll) {
        isAll = true;
        std::thread swim0Thread(distanceUpdate, swimmers[0].getName(), swimmers[0].getDistance());
        std::thread swim1Thread(distanceUpdate, swimmers[1].getName(), swimmers[1].getDistance());
        std::thread swim2Thread(distanceUpdate, swimmers[2].getName(), swimmers[2].getDistance());
        std::thread swim3Thread(distanceUpdate, swimmers[3].getName(), swimmers[3].getDistance());
        std::thread swim4Thread(distanceUpdate, swimmers[4].getName(), swimmers[4].getDistance());
        std::thread swim5Thread(distanceUpdate, swimmers[5].getName(), swimmers[5].getDistance());
        swim0Thread.join();
        swim1Thread.join();
        swim2Thread.join();
        swim3Thread.join();
        swim4Thread.join();
        swim5Thread.join();

        for (size_t i = 0; i < numSwimmers; ++i) {
            if (!swimmers[i].isFinished) {
                swimmers[i].time++;
                swimmers[i].getDistance() += swimmers[i].getSpeed();
                swimmers[i].isFinished = swimmers[i].getDistance() >= 100;
            }
            isAll &= swimmers[i].isFinished;
        }

        swim0Thread.~thread();
        swim1Thread.~thread();
        swim2Thread.~thread();
        swim3Thread.~thread();
        swim4Thread.~thread();
        swim5Thread.~thread();
    }

    for (size_t i = 0; i < numSwimmers; ++i) {
        for (size_t j = i + 1; j < numSwimmers; ++j) {
            if (swimmers[i].time > swimmers[j].time) {
                auto swimmer = swimmers[i];
                swimmers[i] = swimmers[j];
                swimmers[j] = swimmer;
            }
        }
    }

    size_t num = 1;
    for (auto& swimmer : swimmers) {
        std::cout << num << " " << swimmer.getName() << " - " << swimmer.time << std::endl;
        num++;
    }

    return 0;
}
