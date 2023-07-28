#include "disk.h"

#include "ram.h"

#include <fstream>
#include <iostream>
#include <string>

static const std::string path = "data.txt";

void save (void)
{
    int fromRamToRomBuf[sizeBuf];
    read(fromRamToRomBuf, sizeBuf);
    std::ofstream file (path);
    if (!file.is_open()) {
        std::cout << "Error open file" << std::endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(fromRamToRomBuf), sizeof(int) * sizeBuf);
    file.close();
}

void load (void)
{
    int fromRomToRamBuf[sizeBuf];
    std::ifstream file (path);
    if (!file.is_open()) {
        std::cout << "Error open file" << std::endl;
        return;
    }
    file.read(reinterpret_cast<char*>(fromRomToRamBuf), sizeof(int) * sizeBuf);
    write(fromRomToRamBuf, sizeBuf);
    file.close();
}
