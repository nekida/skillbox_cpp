#include <iostream>
#include <string>
#include <map>

int main ()
{
    std::map<std::string, int> lastNameNumPersons;
    std::string inputStr;
    std::cin >> inputStr;

    while (inputStr != "exit") {
        if (inputStr == "Next") {
            if (!lastNameNumPersons.empty()) {
                auto& pickNum = lastNameNumPersons.begin()->second;
                auto& pickName = lastNameNumPersons.begin()->first;
                std::cout << pickName << std::endl;
                if (pickNum > 1)
                    pickNum--;
                else
                    lastNameNumPersons.erase(lastNameNumPersons.find(pickName));
            } else {
                std::cout << "Queue is empty!" << std::endl;
            }
        } else {
            if (lastNameNumPersons.count(inputStr))
                lastNameNumPersons[inputStr]++;
            else
                lastNameNumPersons[inputStr] = 1;
        }

        std::cin >> inputStr;
    }

    return 0;
}
