#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

struct Date {
    int year;
    int month;
    int day;
};

struct MyFriend {
    std::string name;
    Date birthday;
};

const int year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap (int checkYear)
{
    return (checkYear % 400 == 0) || ((checkYear % 4 == 0) && (checkYear % 100 != 0));
}

int getNumOfDaysInYear (const Date& date, int curYear)
{
    int numOfDays = 0;
    for (int i = 0; i < date.month - 1; i++) {
        numOfDays += year[i];
        if (i == 1 && isLeap (curYear))
            numOfDays += 1;
    }
    return numOfDays + date.day - 1;
}

void findTheNearestBirthday (std::vector<MyFriend>& myFriends)
{
    int delta = 365;
    std::vector<MyFriend> findFriends;

    std::time_t t = std::time(nullptr);
    std::tm* local = std::localtime(&t);
    for (auto& myFriend : myFriends) {
        if (myFriend.birthday.month - 1 == local->tm_mon && myFriend.birthday.day == local->tm_mday) {
            std::cout << "Today birthday is " << myFriend.name << std::endl;
        } else {
            int tempDelta = getNumOfDaysInYear(myFriend.birthday, local->tm_year) - local->tm_yday;
            if (tempDelta < delta && tempDelta > 0)
                delta = tempDelta;
        }
    }

    for (auto& myFriend : myFriends) {
        if (getNumOfDaysInYear(myFriend.birthday, local->tm_year) == local->tm_yday + delta)
            findFriends.push_back(myFriend);
    }

    if (!findFriends.empty())
        for (auto& myFriend : findFriends)
            std::cout << "Nearest birthday of " << myFriend.name  << " - " << myFriend.birthday.month
                                                    << '/' << myFriend.birthday.day << std::endl;
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
        std::cout << "Input birthday date of friend (yyyy/mm/dd)" << std::endl;
        char temp;
        std::cin >> myFriend.birthday.year >> temp >> myFriend.birthday.month >> temp >> myFriend.birthday.day;
        myFriends.push_back(myFriend);

        std::cout << "Input name of friend or command \"end\"" << std::endl;
        std::cin >> input;
    }
    findTheNearestBirthday(myFriends);

    return 0;
}
