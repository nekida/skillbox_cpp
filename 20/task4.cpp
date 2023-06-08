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

int getNumBanknote (int sum, int valBanknote)
{
    int num = 0;
    while (sum - valBanknote > 0) {
        num++;
        sum -= valBanknote;
    }
    return num;
}

bool checkAvailability (std::vector<int>& v, int valBanknote, int numBanknote)
{
    int curNum = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == valBanknote)
            curNum++;
    }
    return curNum >= numBanknote;
}

void giveNumOfBanknotes (std::vector<int>& v, int valBanknote, int numBanknote)
{
    for (size_t i = 0; i < v.size() && numBanknote; i++) {
        if (v[i] == valBanknote) {
            v[i] = 0;
            numBanknote--;
        }
    }
}

void giveBanknotes (int freeSpiceATM)
{
    std::cout << "Specify the amount to be issued with an accuracy of 100 rubles" << std::endl;
    int sum;
    std::cin >> sum;

    if (sum % 100) {
        std::cout << "Invalid value" << std::endl;
        return;
    }

    std::vector<int> bankArray(fullATM);
    std::ifstream bankFileIn ("bank.bin", std::ios_base::binary);
    if (!bankFileIn.is_open()) {
        std::cout << "Error open file bank.bin" << std::endl;
        return;
    }
    bankFileIn.read (reinterpret_cast<char*>(bankArray.data()), sizeof(int) * bankArray.size());
    bankFileIn.close ();

    int num5000Banknote = getNumBanknote(sum, 5000);
    int num2000Banknote = getNumBanknote(sum, 2000);
    int num1000Banknote = getNumBanknote(sum, 1000);
    int num500Banknote = getNumBanknote(sum, 500);
    int num100Banknote = getNumBanknote(sum, 100);

    bool checker = true;
    do {
        if (!checkAvailability(bankArray, 5000, num5000Banknote)) {
            checker = false;
            break;
        }
        if (!checkAvailability(bankArray, 2000, num2000Banknote)) {
            checker = false;
            break;
        }
        if (!checkAvailability(bankArray, 1000, num1000Banknote)) {
            checker = false;
            break;
        }
        if (!checkAvailability(bankArray, 500, num500Banknote)) {
            checker = false;
            break;
        }
        if (!checkAvailability(bankArray, 100, num100Banknote)) {
            checker = false;
            break;
        }
    } while (false);
    if (!checker) {
        std::cout << "There are no such banknotes in the right quantity" << std::endl;
        return;
    } else {
        giveNumOfBanknotes (bankArray, 5000, num5000Banknote);
        giveNumOfBanknotes (bankArray, 2000, num2000Banknote);
        giveNumOfBanknotes (bankArray, 1000, num1000Banknote);
        giveNumOfBanknotes (bankArray, 500, num500Banknote);
        giveNumOfBanknotes (bankArray, 100, num100Banknote);
        std::cout << "The sum of money " << sum << " was issued" << std::endl;
    }

    std::ofstream bankFileOut ("bank.bin", std::ios_base::binary);
    if (!bankFileOut.is_open()) {
        std::cout << "Error open file bank.bin" << std::endl;
        return;
    }
    bankFileOut.write (reinterpret_cast<const char*>(bankArray.data()), sizeof(int) * bankArray.size());
    bankFileOut.close ();
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
