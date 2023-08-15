#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <vector>
#include <mutex>

std::mutex station_access;

class Train {
    size_t maxTime = 0;

    size_t curTime = 0;

    char name;

public:
    Train(size_t time, char name)
            : maxTime(time), name(name) {}

    size_t getCurTime() const { return curTime; }

    size_t getMaxTime() const { return maxTime; }

    void incCurTime() { curTime++; }

    char getName() const { return name; }

    std::thread thr;

    bool isLeftStation = false;
};

void timeUpdate (Train& train)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    train.incCurTime();
    if (train.getCurTime() >= train.getMaxTime()) {
        std::cout << "Train " << train.getName() << "waiting for free space the station" << std::endl;
        station_access.lock();
        std::cout << "Train " << train.getName() << "arrived at the station" << std::endl;
        std::string cmd;
        std::cin >> cmd;
        while (cmd != "depart") {
            std::cin >> cmd;
        }
        station_access.unlock();
        std::cout << "Train " << train.getName() << "lesf at the station" << std::endl;
        train.isLeftStation = true;
    }
    station_access.unlock();
}

int main ()
{
    constexpr int numTrains = 3;
    char namesOfTrains[numTrains] = {'A', 'B', 'C'};
    std::vector<Train> trains;
    for (int i = 0; i < numTrains; ++i) {
        std::cout << "Enter the travel time in seconds to the station for train " << namesOfTrains[i] << std::endl;
        size_t time;
        std::cin >> time;
        Train train(time, namesOfTrains[i]);
        trains.push_back(train);
        trains[i].thr = std::thread(timeUpdate, std::ref(trains[i]));
    }

    for (int i = 0; i < numTrains; ++i)
        trains[i].thr.join();

    bool isAllTrainsLeftStation = false;
    while(!isAllTrainsLeftStation) {
        isAllTrainsLeftStation = true;
        for (int i = 0; i < numTrains; ++i)
            isAllTrainsLeftStation &= trains[i].isLeftStation;
    }

    return 0;
}
