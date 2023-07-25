#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

int main ()
{
    std::cout << "Enter minutes and seconds (mm:ss):" << std::endl;
    int min, sec;
    char temp;
    std::cin >> min >> temp >> sec;

    std::time_t curTime = std::time(nullptr);
    std::tm targetTime = *std::localtime(&curTime);
    std::tm *tickTime = std::localtime(&curTime);
    targetTime.tm_min += min;
    targetTime.tm_sec += sec;
    int seconds = min * 60 + sec;

    while (targetTime.tm_min - tickTime->tm_min || targetTime.tm_sec - tickTime->tm_sec) {
        int saveSec = tickTime->tm_sec;
        std::time_t newTime = std::time(nullptr);
        tickTime = std::localtime(&newTime);
        if (saveSec != tickTime->tm_sec) {
            int tempMin = seconds > 60 ? (seconds / 60) : 0;
            int tempSec = seconds > 60 ? (seconds % 60) : seconds;
            std::cout << "Time left -> " << tempMin << ':' << tempSec << std::endl;
            seconds--;
        }
    }
    std::cout << "DING! DING! DING!" << std::endl;

    return 0;
}
