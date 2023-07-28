#include "kbd.h"

#include "ram.h"

#include <iostream>

void input (void)
{
    int readBuf[sizeBuf];
    std::cout << "Enter " << sizeBuf << " numbers for written:" << std::endl;
    for (int i = 0; i < sizeBuf; ++i)
        std::cin >> readBuf[i];
    write (readBuf, sizeBuf);
}
