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

    if (freeSpiceATM != 0) {
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = i + 1; j < size; j++) {
                if (bankArray[i] == 0 && bankArray[j] != 0) {
                    bankArray[i] = bankArray[j];
                    bankArray[j] = 0;
                }
            }
        }
    }

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

bool checkAvailability (std::vector<int>& v, int sum)
{
    for (size_t i = 0; i < v.size(); i++) {
        if (sum - v[i] < 0)
            continue;
        else if (sum == 0)
            break;
        else if (v[i] != 0)
            sum -= v[i];
    }
    return sum == 0;
}

int giveAmount (std::vector<int>& v, int sum)
{
    int result = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (sum - v[i] < 0)
            continue;
        else if (sum == 0)
            break;
        else if (v[i] != 0) {
            sum -= v[i];
            std::cout << "A banknote has been issued: " << v[i] << std::endl;
            result += v[i];
            v[i] = 0;
        }
    }
    return result;
}

void giveBanknotes ()
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

    if (checkAvailability (bankArray, sum)) {
        int resSum = giveAmount (bankArray, sum);
        std::cout << "The sum of money " << resSum << " was issued" << std::endl;
    }
    else
        std::cout << "There are no such banknotes in the right quantity" << std::endl;

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
            giveBanknotes();
    }

    return 0;
}
