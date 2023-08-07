#include <iostream>
#include <string>
#include <random>
#include <assert.h>

int getRandomInRange (const int min, const int max)
{
    return min + (rand() % (max - min + 1));
}

class Branch {
    Branch** parent = nullptr;
    Branch** child = nullptr;
    std::string nameElf = "";

public:
    Branch()
    {
        srand(time(NULL));
        int numBigBranch = getRandomInRange(3, 5);
        child = new Branch * [numBigBranch];
        for (int i = 0; i < numBigBranch; ++i) {
            child[i]->parent = &this;
            child[i]->child = nullptr;
        }
    }
};

int main ()
{
    Branch villageOfElfs;

    return 0;
}
