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
    while (sum - valBanknote >= 0) {
        num++;
        sum -= valBanknote;
    }
    return num;
}

int numAvailability (std::vector<int>& v, int valBanknote)
{
    int cnt = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == valBanknote)
            cnt++;
    }
    return cnt;
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

    int needNum5000Banknote = sum / 5000;
    sum %= 5000;
    int needNum2000Banknote = sum / 2000;
    sum %= 2000;
    int needNum1000Banknote = sum / 1000;
    sum %= 1000;
    int needNum500Banknote = sum / 500;
    sum %= 500;
    int needNum100Banknote = sum / 100;

    int availNum5000Banknote = numAvailability (bankArray, 5000);
    int availNum2000Banknote = numAvailability (bankArray, 2000);
    int availNum1000Banknote = numAvailability (bankArray, 1000);
    int availNum500Banknote = numAvailability (bankArray, 500);
    int availNum100Banknote = numAvailability (bankArray, 100);

    int resNum5000Banknote = 0;
    if (availNum5000Banknote >= needNum5000Banknote) {
        resNum5000Banknote = needNum5000Banknote;
    } else {
        resNum5000Banknote = availNum5000Banknote;
        int delta = needNum5000Banknote - availNum5000Banknote;
        while (delta) {
            needNum2000Banknote += 2;
            needNum1000Banknote += 1;
            --delta;
        }
    }
    int resNum2000Banknote = 0;
    if (availNum2000Banknote >= needNum2000Banknote) {
        resNum2000Banknote = needNum2000Banknote;
    } else {
        resNum2000Banknote = availNum2000Banknote;
        int delta = needNum2000Banknote - availNum2000Banknote;
        while (delta) {
            needNum1000Banknote += 2;
            --delta;
        }
    }
    int resNum1000Banknote = 0;
    if (availNum1000Banknote >= needNum1000Banknote) {
        resNum1000Banknote = needNum1000Banknote;
    } else {
        resNum1000Banknote = availNum1000Banknote;
        int delta = needNum1000Banknote - availNum1000Banknote;
        while (delta) {
            needNum500Banknote += 2;
            --delta;
        }
    }
    int resNum500Banknote = 0;
    if (availNum500Banknote >= needNum500Banknote) {
        resNum500Banknote = needNum500Banknote;
    } else {
        resNum500Banknote = availNum500Banknote;
        int delta = needNum500Banknote - availNum500Banknote;
        while (delta) {
            needNum100Banknote += 5;
            --delta;
        }
    }
    int resNum100Banknote = needNum100Banknote;

    bool checker = true;
    do {
        if (resNum5000Banknote > availNum5000Banknote) {
            checker = false;
            break;
        }
        if (resNum2000Banknote > availNum2000Banknote) {
            checker = false;
            break;
        }
        if (resNum1000Banknote > availNum1000Banknote) {
            checker = false;
            break;
        }
        if (resNum500Banknote > availNum500Banknote) {
            checker = false;
            break;
        }
        if (resNum100Banknote > availNum100Banknote) {
            checker = false;
            break;
        }
    } while (false);
    if (!checker) {
        std::cout << "There are no such banknotes in the right quantity" << std::endl;
        return;
    } else {
        giveNumOfBanknotes (bankArray, 5000, resNum5000Banknote);
        giveNumOfBanknotes (bankArray, 2000, resNum2000Banknote);
        giveNumOfBanknotes (bankArray, 1000, resNum1000Banknote);
        giveNumOfBanknotes (bankArray, 500, resNum500Banknote);
        giveNumOfBanknotes (bankArray, 100, resNum100Banknote);
        int resSum = 5000 * resNum5000Banknote + 2000 * resNum2000Banknote + 1000 * resNum1000Banknote +
                                                            500 * resNum500Banknote + 100 * resNum100Banknote;
        std::cout << "The sum of money " << resSum << " was issued" << std::endl;
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
