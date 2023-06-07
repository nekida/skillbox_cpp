#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

static constexpr int fullATM = 1000;

int getFreeSpaceInBank ()
{
    std::ifstream bankFile ("bank.bin", std::ios_base::binary);
    if (!bankFile.is_open()) {
        std::cout << "Error open file bank.bin" << std::endl;
        return -1;
    }

    std::vector<int> bankArray(fullATM);
    size_t size = bankArray.size();

    bankFile.read (reinterpret_cast<char*>(bankArray.data()), sizeof(int) * size);
    bankFile.close ();

    int cntZeros = 0;
    for (size_t i = 0; i < size; i++)
        if (bankArray[i] == 0)
            cntZeros++;

    return cntZeros;
}

void addBanknotes (int freeSpiceATM)
{
    std::srand(std::time(nullptr));
    std::vector<int> bankArray(fullATM);
    size_t size = bankArray.size();

    std::ifstream bankFileIn ("bank.bin", std::ios_base::binary);
    if (!bankFileIn.is_open()) {
        std::cout << "Error open file bank.bin" << std::endl;
        return;
    }

    bankFileIn.read (reinterpret_cast<char*>(bankArray.data()), sizeof(int) * size);
    bankFileIn.close ();

    int startPos = size - freeSpiceATM;
    while (freeSpiceATM > 0) {
        int arrayBanknotes[] = {100, 500, 1000, 2000, 5000};
        int ranI = std::rand() % 5;
        int banknote = arrayBanknotes[ranI];

        int ranNum = std::rand() % freeSpiceATM + 1;

        for (int i = startPos; i < startPos + ranNum; ++i)
            bankArray[i] = banknote;

        startPos += ranNum;
        freeSpiceATM -= ranNum;
    }

    std::ofstream bankFileOut ("bank.bin", std::ios_base::binary);
    if (!bankFileOut.is_open()) {
        std::cout << "Error open file bank.bin" << std::endl;
        return;
    }
    bankFileOut.write (reinterpret_cast<const char*>(bankArray.data()), sizeof(int) * size);
    bankFileOut.close ();
}

void giveBanknotes (int freeSpiceATM)
{
    
}

int main ()
{
    char ch;
    std::cout << "Enter symbol ('+' - add banknotes, '-' - give banknotes)" << std::endl;
    std::cin >> ch;

    if (ch == '+') {
        int free = getFreeSpaceInBank ();
        if (free < 0)
            return 0;
        else if (free == 0)
            std::cout << "There is no free space in the ATM" << std::endl;
        else
            addBanknotes(free);
    } else if (ch == '-') {
        int free = getFreeSpaceInBank ();
        if (free < 0)
            return 0;
        else if (free == fullATM)
            std::cout << "There are no banknotes in the ATM" << std::endl;
        else
            giveBanknotes(free);
    }

    return 0;
}
