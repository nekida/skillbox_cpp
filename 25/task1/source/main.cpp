#include <iostream>
#include <string>

#include "surgical_instruments.h"

bool checkCoordinates (const Coordinates& srcA, const Coordinates& srcB, const Coordinates& destA, const Coordinates& destB)
{
    return  srcA.x == destA.x && srcA.y == destA.y &&
            srcB.x == destB.x && srcB.y == destB.y;
}

void printMessageAndFillStructure (const std::string& message, Coordinates& a, Coordinates& b)
{
    std::cout << "Enter the coordinates of the beginning of the " << message << ": " << std::endl;
    std::cin >> a.x >> a.y;
    std::cout << "Enter the coordinates of the end of the " << message << ": " << std::endl;
    std::cin >> b.x >> b.y;
}

int main()
{
    std::string command;
    Coordinates coorStart1, coorEnd1, coorStart2, coorEnd2, coorOnce;

    do {
        std::cout << "Enter name of instruments: " << std::endl;
        std::cin >> command;
        if (command != "scalpel")
            std::cout << "This tool is not suitable!" << std::endl;
    } while (command != "scalpel");

    printMessageAndFillStructure("cut", coorStart1, coorEnd1);
    scalpel(coorStart1, coorEnd1);

    std::cout << "Enter name of instruments: " << std::endl;
    std::cin >> command;
    while (command != "suture") {
        if (command == "hemostat") {
            std::cout << "Enter coordinates:: " << std::endl;
            std::cin >> coorOnce.x >> coorOnce.y;
            hemostat(coorOnce);
        } else if (command == "tweezers") {
            std::cout << "Enter coordinates:: " << std::endl;
            std::cin >> coorOnce.x >> coorOnce.y;
            tweezers(coorOnce);
        }
        std::cout << "Enter name of instruments: " << std::endl;
        std::cin >> command;
    }

    while (!checkCoordinates(coorStart1, coorEnd1, coorStart2, coorEnd2)) {
        printMessageAndFillStructure("seam", coorStart2, coorEnd2);
        if (!checkCoordinates(coorStart1, coorEnd1, coorStart2, coorEnd2)) {
            std::cout << "Coordinates don't match!" << std::endl;
            continue;
        }
    }
    suture(coorStart2, coorEnd2);

    return 0;
}