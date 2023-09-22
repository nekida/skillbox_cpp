#include <iostream>
#include <string>
#include <ctime>

class Fish {
};

class Boot {
};

class Field {
public:
    Fish* fish = nullptr;

    Boot* boot = nullptr;
};

struct FishingOk {
    size_t numTry;
};

struct FishingBad {
};

struct FishingNone {
};

int main ()
{
    std::srand(std::time(nullptr));

    Field field[9];
    field[std::rand() % 9].fish = new Fish();

    size_t numBoots = 3;
    while (numBoots != 0) {
        int pos = std::rand() % 9;
        if (field[pos].fish == nullptr && field[pos].boot == nullptr) {
            field[pos].boot = new Boot();
            numBoots--;
        }
    }
    std::cout << "The field has been initialized" << std::endl;
    size_t numSector, numTry = 0;

    while (1) {
        std::cout << "Enter the number of the sector where to cast the fishing rod (1 - 9)" << std::endl;
        std::cin >> numSector;
        numSector--;
        numTry++;
        try {
            if (field[numSector].fish != nullptr)
                throw FishingOk{numTry};
            else if (field[numSector].boot != nullptr)
                throw FishingBad{};
            else
                throw FishingNone{};
        } catch (const FishingOk& ok) {
            std::cout << "Fishing was a success! You caught a fish on your " << ok.numTry << " try" << std::endl;
            return 0;
        } catch (const FishingBad& bad) {
            std::cout << "You caught a boot. Please, repeat" << std::endl;
        } catch (const FishingNone& none) {
            std::cout << "You didn't catch anything. Please, repeat" << std::endl;
        }
    }

    return 0;
}
