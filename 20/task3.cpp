#include <iostream>
#include <fstream>
#include <string>

int main ()
{
    std::ifstream fileIn ("river.txt");
    if (!fileIn.is_open()) {
        std::cout << "Error open file river.txt" << std::endl;
        return 0;
    }

    std::cout << "Enter the type of fish you want to catch" << std::endl;
    std::string catchFish;
    std::cin >> catchFish;
    int fishCounter = 0;

    while (!fileIn.eof()) {
        std::string riverFish;
        fileIn >> riverFish;
        if (catchFish == riverFish) {
            std::ofstream fileOut ("basket.txt", std::ofstream::app);
            if (!fileOut.is_open()) {
                std::cout << "Error open file basket.txt" << std::endl;
                return 0;
            }
            fileOut << riverFish << std::endl;
            fishCounter++;
            fileOut.close ();
        }
        else
            continue;

        std::cout << "Enter the type of fish you want to catch" << std::endl;
        std::cin >> catchFish;
    }

    std::cout << "Fish were caught for the current catch " << fishCounter << std::endl;
    fileIn.close();

    return 0;
}
