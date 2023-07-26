#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

int main ()
{
    std::cout << "Enter minutes and seconds (mm:ss):" << std::endl;
    std::tm time;
    std::cin >> std::get_time(&time, "%M:%S");

    std::time_t curTime = std::time(nullptr);
    std::tm targetTime = *std::localtime(&curTime);
    std::tm *tickTime = std::localtime(&curTime);
    targetTime.tm_min += time.tm_min;
    targetTime.tm_sec += time.tm_sec;
    int seconds = time.tm_min * 60 + time.tm_sec;

    while (targetTime.tm_min - tickTime->tm_min || targetTime.tm_sec - tickTime->tm_sec) {
        int saveSec = tickTime->tm_sec;
        std::time_t newTime = std::time(nullptr);
        tickTime = std::localtime(&newTime);
        if (saveSec != tickTime->tm_sec) {
            int tempMin = seconds > 59 ? (seconds / 59) : 0;
            int tempSec = seconds >= 60 ? (seconds % 60) : seconds;
            std::cout << "Time left -> " << tempMin << ':' << tempSec << std::endl;
            seconds--;
        }
    }
    std::cout << "DING! DING! DING!" << std::endl;

    return 0;
}
