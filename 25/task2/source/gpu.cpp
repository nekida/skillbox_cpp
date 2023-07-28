#include "gpu.h"

#include <iostream>

#include "ram.h"

void display (void)
{
    int readData[sizeBuf];
    read(readData, sizeBuf);
    for (uint8_t i = 0; i < sizeBuf; ++i)
        std::cout << readData[i] << std::endl;
}
