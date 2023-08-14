#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <vector>
#include <mutex>
#include <algorithm>

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

    std::thread thr;
};

std::mutex stdio_access;

void distanceUpdate (Swimmer& swimmer)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    stdio_access.lock();
    std::cout << swimmer.getName();
    if (!swimmer.isFinished) {
        swimmer.getDistance() += swimmer.getSpeed();
        swimmer.time++;
        swimmer.isFinished = swimmer.getDistance() >= 100;
    }
    swimmer.isFinished ? std::cout << " finished" : std::cout << " swimming " << swimmer.getDistance() << " meters";
    std::cout << std::endl;
    stdio_access.unlock();
}

int main ()
{
    constexpr int numSwimmers = 6;
    std::vector<Swimmer> swimmers(numSwimmers);
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

        for (size_t i = 0; i < numSwimmers; ++i)
            swimmers[i].thr = std::thread(distanceUpdate, std::ref(swimmers[i]));

        for (size_t i = 0; i < numSwimmers; ++i)
            swimmers[i].thr.join();

        for (size_t i = 0; i < numSwimmers; ++i) {
            isAll &= swimmers[i].isFinished;
        }
    }

    std::sort(swimmers.begin(), swimmers.end(),
            [](const Swimmer& a, const Swimmer& b) {
                return a.time < b.time;
            });

    size_t num = 1;
    for (auto& swimmer : swimmers) {
        std::cout << num << " " << swimmer.getName() << " - " << swimmer.time << std::endl;
        num++;
    }

    return 0;
}
