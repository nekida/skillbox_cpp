#include "ram.h"

static int ramBuf[sizeBuf];

void write (const int* const dataWr, int size = 8)
{
    for (int i = 0; i < size; ++i)
        ramBuf[i] = dataWr[i];
}

void read (int* const rdBuf, int size = 8)
{
    for (int i = 0; i < size; ++i)
        rdBuf[i] = ramBuf[i];
}
