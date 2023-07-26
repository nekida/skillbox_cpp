#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

struct MyFriend {
    std::string name;
    std::tm birthday;
};

void findTheNearestBirthday (std::vector<MyFriend>& myFriends)
{
    int delta = 365;
    std::vector<MyFriend> findFriends;

    std::time_t t = std::time(nullptr);
    std::tm saveLocal = *std::localtime(&t);
    for (auto& myFriend : myFriends) {

        std::time_t next = mktime(&myFriend.birthday);
        myFriend.birthday = *std::localtime(&next);

        if (myFriend.birthday.tm_mon == saveLocal.tm_mon && myFriend.birthday.tm_mday == saveLocal.tm_mday) {
            std::cout << "Today birthday is " << myFriend.name << std::endl;
        } else {
            int tempDelta = myFriend.birthday.tm_yday - saveLocal.tm_yday;
            if (tempDelta < delta && tempDelta > 0)
                delta = tempDelta;
        }
    }

    for (auto& myFriend : myFriends) {
        if (myFriend.birthday.tm_yday == saveLocal.tm_yday + delta)
            findFriends.push_back(myFriend);
    }

    if (!findFriends.empty())
        for (auto& myFriend : findFriends)
            std::cout << "Nearest birthday of " << myFriend.name  << " - " << myFriend.birthday.tm_mon + 1
                                                    << '/' << myFriend.birthday.tm_mday << std::endl;
}

int main ()
{
    std::vector<MyFriend> myFriends;
    std::string input;
    std::cout << "Input name of friend or command \"end\"" << std::endl;
    std::cin >> input;
    while (input != "end") {
        MyFriend myFriend;
        myFriend.name = input;
        std::cout << "Input birthday date of friend " << myFriend.name << " (yyyy/mm/dd)" << std::endl;
        char temp;
        std::time_t t = std::time(nullptr);
        myFriend.birthday = *std::localtime(&t);
        std::cin >> myFriend.birthday.tm_year >> temp >> myFriend.birthday.tm_mon >> temp >> myFriend.birthday.tm_mday;
        myFriend.birthday.tm_mon -= 1; // В tm месяцы идут с нуля
        myFriends.push_back(myFriend);

        std::cout << "Input name of friend or command \"end\"" << std::endl;
        std::cin >> input;
    }
    findTheNearestBirthday(myFriends);

    return 0;
}
