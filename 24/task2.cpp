#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

struct

struct MyFriend {
    std::string name;
    std::tm bithday;
};

void findTheNearestBirthday (std::vector<MyFriend>& myFriends)
{
    int delta = 365;
    int prevDelta = 365;
    std::vector<MyFriend> findFriends;

    std::time_t t = std::time(nullptr);
    std::tm* local = std::localtime(&t);
    for (auto& myFriend : myFriends) {
        if (myFriend.bithday.tm_mon == local->tm_mon && myFriend.bithday.tm_mday == local->tm_mday) {
            std::cout << "Today bithday is " << myFriend.name << std::endl;
        } else {
            std::cout << myFriend.bithday.tm_yday;
            std::cout << local->tm_yday;
            int tempDelta = myFriend.bithday.tm_yday - local->tm_yday;
            if (tempDelta < delta)
                delta = tempDelta;
        }
    }

    for (auto& myFriend : myFriends) {
        if (myFriend.bithday.tm_yday == local->tm_yday + delta)
            findFriends.push_back(myFriend);
    }

    if (!findFriends.empty())
        for (auto& myFriend : findFriends)
            std::cout << "Nearest bithday of " << myFriend.name  << " - " << std::put_time(&myFriend.bithday, "%m/%d") << std::endl;
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

        std::time_t t = std::time(nullptr);
        myFriend.bithday = *std::localtime(&t);
        std::cout << "Input bithday date of friend (yyyy/mm/dd)" << std::endl;
        std::cin >> std::get_time(&myFriend.bithday, "%Y/%m/%d");
        myFriends.push_back(myFriend);

        // std::cout << myFriend.name << " - " << std::put_time(&myFriend.bithday, "%m/%d") << std::endl;

        std::cout << "Input name of friend or command \"end\"" << std::endl;
        std::cin >> input;
    }
    findTheNearestBirthday(myFriends);

    return 0;
}
