#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <vector>
#include <mutex>

std::mutex station_access;

class Train {
    size_t time = 0;

    char name;

public:
    Train(size_t time, char name)
            : time(time), name(name) {}

    size_t getTime() const { return time; }

    char getName() const { return name; }

    bool isLeftStation = false;
};

void timeUpdate (Train& train)
{
    std::this_thread::sleep_for(std::chrono::seconds(train.getTime()));
    if (!train.isLeftStation) {
        std::cout << "Train " << train.getName() << " waiting for free space the station" << std::endl;
        station_access.lock();
        std::cout << "Train " << train.getName() << " arrived at the station" << std::endl;
        std::string cmd;
        std::cin >> cmd;
        while (cmd != "depart")
            std::cin >> cmd;
        station_access.unlock();
        std::cout << "Train " << train.getName() << " left at the station" << std::endl;
        train.isLeftStation = true;
    }
}

int main ()
{
    constexpr int numTrains = 3;
    char namesOfTrains[numTrains] = {'A', 'B', 'C'};
    std::vector<Train> trains;
    trains.reserve(numTrains);
    for (int i = 0; i < numTrains; ++i) {
        std::cout << "Enter the travel time in seconds to the station for train " << namesOfTrains[i] << std::endl;
        size_t time;
        std::cin >> time;
        trains.push_back({time, namesOfTrains[i]});
    }

    std::thread thrs[numTrains];
    for (int i = 0; i < numTrains; ++i)
        thrs[i] = std::thread(timeUpdate, std::ref(trains[i]));

    for (int i = 0; i < numTrains; ++i)
        thrs[i].join();

    bool isAllTrainsLeftStation = false;
    while(!isAllTrainsLeftStation) {
        isAllTrainsLeftStation = true;

        for (int i = 0; i < numTrains; ++i) {
            if (!trains[i].isLeftStation) {
                thrs[i] = std::thread(timeUpdate, std::ref(trains[i]));
                thrs[i].join();
            }
        }

        for (int i = 0; i < numTrains; ++i)
            isAllTrainsLeftStation &= trains[i].isLeftStation;
    }

    return 0;
}
