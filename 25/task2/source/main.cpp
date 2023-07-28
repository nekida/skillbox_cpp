#include <iostream>
#include <string>

#include "cpu.h"
#include "gpu.h"
#include "ram.h"
#include "disk.h"
#include "kbd.h"

int main ()
{
    std::cout << "Enter command (sum, save, load, input, display, exit)" << std::endl;
    std::string command;
    std::cin >> command;
    while (command != "exit") {
        if (command == "sum") {
            int readData[sizeBuf];
            read(readData, sizeBuf);
            compute(readData, sizeBuf);
        } else if (command == "save")
            save();
        else if (command == "load")
            load();
        else if (command == "input")
            input();
        else if (command == "display")
            display();
        else
            std::cout << "Unsupported command" << std::endl;

        std::cout << "Enter command (sum, save, load, input, display, exit)" << std::endl;
        std::cin >> command;
    }

    return 0;
}