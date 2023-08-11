#include <iostream>
#include <string>
#include <random>
#include <assert.h>

int getRandomInRange (const int min, const int max)
{
    return min + (rand() % (max - min + 1));
}

class Branch {

    std::string nameElf = "";

    int numBigBranch = 0;

    int numMidBranch = 0;

public:
    Branch* parent = nullptr;

    Branch* child = nullptr;

    Branch()
    {
        srand(time(NULL));
        numBigBranch = getRandomInRange(3, 5);
        numMidBranch = getRandomInRange(2, 3);
    }

    int getNumBigBranch() { return numBigBranch; }

    int getNumMidBranch() { return numMidBranch; }

    std::string getNameOfElf() { return nameElf; }

    void setNameOfElf (std::string inName) { nameElf = inName; }

    Branch* getBranchWithElf(std::string inName) {
        if (parent == nullptr && child != nullptr) {
            for (int i = 0; i < getNumBigBranch(); ++i) {
                if (inName == child[i].getNameOfElf())
                    return &child[i];
            }
            child->getBranchWithElf(inName);
        } else if (parent != nullptr && child != nullptr) {
            for (int i = 0; i < getNumMidBranch(); ++i) {
                if (inName == child[i].getNameOfElf())
                    return &child[i];
            }
            child->getBranchWithElf(inName);
        }
        return nullptr;
    }
};

int getNumNeighboursOnBigBranch(Branch* inBranch)
{
    int numNeighbours = 0;
    if (inBranch->parent != nullptr && inBranch->child != nullptr) {
        for (int i = 0; i < inBranch->getNumMidBranch(); ++i) {
            if (inBranch->child[i].getNameOfElf() != "")
                numNeighbours++;
        }
    }
}

int main ()
{
    Branch villageOfElfs[5];
    for (int i = 0; i < 5; i++) {
        int numBigBranch = villageOfElfs[i].getNumBigBranch();
        villageOfElfs[i].child = new Branch [numBigBranch];
        villageOfElfs[i].parent = nullptr;
        for (int j = 0; j < numBigBranch; ++j) {
            int numMidBranch = villageOfElfs[i].getNumMidBranch();
            villageOfElfs[i].child[j].child = new Branch [numMidBranch];
            villageOfElfs[i].child[j].parent = &villageOfElfs[i];
            std::cout << "Enter the name of the elf living on " << j + 1 << " large branch of " << i + 1 << " tree" << std::endl;
            std::string name = "";
            std::cin >> name;
            if (name == "none" || name == "None") name = "";
            villageOfElfs[i].child[j].setNameOfElf(name);
            for (int k = 0; k < numMidBranch; ++k) {
                villageOfElfs[i].child[j].child[k].child = nullptr;
                villageOfElfs[i].child[j].child[k].parent = &villageOfElfs[i].child[j];
                std::cout << "Enter the name of the elf living on " << k + 1 << " middle branch of " << j + 1 << " large branch of " << i + 1 << " tree" << std::endl;
                std::cin >> name;
                if (name == "none" || name == "None") name = "";
                villageOfElfs[i].child[j].child[k].setNameOfElf(name);
            }
        }
    }

    Branch* finded = nullptr;
    for (int i = 0; i < 5; i++) {
        finded = villageOfElfs[i].getBranchWithElf("Nikita");
        if (finded != nullptr)
            break;
    }

    return 0;
}
