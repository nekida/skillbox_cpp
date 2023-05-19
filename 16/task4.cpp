#include <iostream>

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int fromDecToBin (int n)
{
    int ret = 0;
    while (n) {
        ret |= 1 << ((n % 10) - 1);
        n /= 10;
    }
    return ret;
}

void playingMelody (int* notes)
{
    for (int i = 0; i < 12; i++) {
        if (notes[i] & DO)
            std::cout << "DO ";
        if (notes[i] & RE)
            std::cout << "RE ";
        if (notes[i] & MI)
            std::cout << "MI ";
        if (notes[i] & FA)
            std::cout << "FA ";
        if (notes[i] & SOL)
            std::cout << "SOL ";
        if (notes[i] & LA)
            std::cout << "LA ";
        if (notes[i] & SI)
            std::cout << "SI ";
        std::cout << std::endl;
    }
}

int main ()
{
    std::string combinations[12];
    int numbers[12], binNumbers[12];
    std::cout << "Enter the 12 combinations of notes" << std::endl;
    for (int i = 0; i < 12; i++)
        std::cin >> combinations[i];
    for (int i = 0; i < 12; i++)
        numbers[i] = std::stoi(combinations[i]);
    for (int i = 0; i < 12; i++)
        binNumbers[i] = fromDecToBin(numbers[i]);\
    std::cout << "Playing a melody:" << std::endl;
    playingMelody (binNumbers);

    return 0;
}
