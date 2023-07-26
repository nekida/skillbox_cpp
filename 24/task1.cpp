#include <iostream>
#include <vector>
#include <string>
#include <ctime>

enum StatusTask {
    completed = 0,
    running = 1
};

struct Task {
    std::string name;
    StatusTask status;
    std::time_t beginTime;
    std::time_t endTime;
};

struct Time {
    int hours;
    int minutes;
    int seconds;
};

Time getTimeInHours (const std::time_t& startTime, const std::time_t& endTime)
{
    Time retval;
    std::time_t delta = endTime - startTime;
    retval.hours = (delta > 3600) ? delta / 3600 : 0;
    delta %= 3600;
    retval.minutes = (delta > 60) ? delta / 60 : 0;
    delta %= 60;
    retval.seconds = delta;
    return retval;
}

int main ()
{
    std::vector<Task> tasks;
    std::string command;

    std::cout << "> Enter the command:" << std::endl;
    std::cin >> command;
    while (command != "exit") {
        if (command == "begin") {
            Task task;
            std::cout << "> Enter name of task:" << std::endl;
            std::cin >> task.name;
            if (!tasks.empty()) {
                Task& t = tasks.back();
                if (t.status == running)
                    t.status = completed;
            }
            task.status = running;
            task.beginTime = std::time(nullptr);
            tasks.push_back(task);
        } else if (command == "end") {
            Task& t = tasks.back();
            if (!tasks.empty() && t.status == running) {
                    t.status = completed;
                    t.endTime = std::time(nullptr);
            }
        } else if (command == "info") {
            if (tasks.empty()) {
                std::cout << "> There are no tasks!" << std::endl;
            } else {
                for (const auto& task : tasks) {
                    if (task.status == completed) {
                        Time time = getTimeInHours(task.beginTime, task.endTime);
                        std::cout << "> Name of complete task: " << task.name << ". Execution time: "
                                << time.hours << " hours " << time.minutes << " minutes " << time.seconds
                                        << " seconds" << std::endl;
                    } else if (task.status == running)
                        std::cout << "> Name of running task: " << task.name << std::endl;
                }
            }
        } else
            std::cout << "> Unsupported command!" << std::endl;

        std::cout << "> Enter the command:" << std::endl;
        std::cin >> command;
    }

    return 0;
}
