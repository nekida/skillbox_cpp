#include <iostream>
#include <fstream>
#include <string>

int main ()
{
    std::cout << "Enter file path" << std::endl;
    std::string path;
    std::cin >> path;

    std::ifstream file;
    file.open(path, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error open file" << std::endl;
        return 0;
    }
    int totalSum, maxVal;
    totalSum = maxVal = 0;
    std::string firstNameMaxSum, lastNameMaxSum;
    while (!file.eof()) {
        std::string firstName, lastName, date;
        int value;
        file >> firstName >> lastName >> value >> date;
        if (value > maxVal) {
            maxVal = value;
            firstNameMaxSum = firstName;
            lastNameMaxSum = lastName;
        }
        totalSum += value;
    }
    file.close();

    std::cout << "Total summary is " << totalSum << std::endl;
    std::cout << "largest recipient of funds is " << firstNameMaxSum << " " << lastNameMaxSum << std::endl;

    return 0;
}
