#include <iostream>
#include <fstream>
#include <string>

bool checkName (const std::string& name)
{
    if (name.empty ())
        return false;
    if (name[0] < 'A' || name[0] > 'Z')
        return false;
    for (size_t i = 1; i < name.size(); ++i)
        if (name[i] < 'a' || name[i] > 'z')
            return false;
    return true;
}

bool checkDate (const std::string& date)
{
    int d = std::stoi(date.substr(0, 2));
    int m = std::stoi(date.substr(3, 2));
    int y = std::stoi(date.substr(6, 4));
    if (d < 0 || d > 31)
        return false;
    if (m < 0 || m > 12)
        return false;
    if (y < 1950 || y > 2023)
        return false;
    return true;
}

bool checkSum (const std::string& sum)
{
    if (sum[0] == '-')
        return false;
    return true;
}

int main ()
{
    std::cout << "Enter file path" << std::endl;
    std::string path;
    std::cin >> path;

    std::cout << "Enter first name, last name, date (dd.mm.yyyy) and summary:" << std::endl;
    std::string firstName, lastName, date, sum;
    std::cin >> firstName >> lastName >> date >> sum;

    std::ofstream file (path, std::ofstream::app);
    if (!file.is_open()) {
        std::cout << "Error open file" << std::endl;
        return 0;
    }
    if (checkName (firstName) && checkName (lastName) && checkDate (date) && checkSum (sum)) {
        file << firstName << ' ' << lastName << ' ' << date << ' ' << sum << std::endl;
        std::cout << "Write is ok" << std::endl;
    }
    else
        std::cout << "Incorrect data. Write failed" << std::endl;
    file.close();

    return 0;
}
