#include <iostream>
#include <string>
#include <random>
#include <assert.h>
#include <vector>

static constexpr int numOfTree = 1;

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
                else {
                    for (int j = 0; j < getNumMidBranch(); ++j) {
                        if (inName == child[i].child[j].getNameOfElf())
                            return &child[i].child[j];
                    }
                }
            }
        }
        return nullptr;
    }
};

std::vector<std::string> getNameNeighboursOnBigBranch(Branch* inBranch, std::string inName)
{
    std::vector<std::string> namesOfNeighbours;
    Branch* branch = nullptr;
    if (inBranch->parent != nullptr && inBranch->child != nullptr)
        branch = inBranch->child;
    else if (inBranch->parent != nullptr && inBranch->child == nullptr) {
        std::string nameOfElfOnBigBranch = inBranch->parent->getNameOfElf();
        if (nameOfElfOnBigBranch != "" && nameOfElfOnBigBranch != "None" && nameOfElfOnBigBranch != "none")
            namesOfNeighbours.push_back(nameOfElfOnBigBranch);
        branch = inBranch->parent->child;
    } else
        return namesOfNeighbours;
    int numBranch = branch->getNumMidBranch();
    for (int i = 0; i < numBranch; ++i) {
        std::string name = branch[i].getNameOfElf();
        if (name != "" && name != inName && name != "None" && name != "none")
            namesOfNeighbours.push_back(name);
    }
    return namesOfNeighbours;
}

int main ()
{
    Branch villageOfElfs[numOfTree];
    for (int i = 0; i < numOfTree; i++) {
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

    std::cout << "Enter the name of the elf whose neighbors you want to find" << std::endl;
    std::string searchName;
    std::cin >> searchName;
    Branch* finded = nullptr;
    for (int i = 0; i < numOfTree; i++) {
        finded = villageOfElfs[i].getBranchWithElf(searchName);
        if (finded != nullptr)
            break;
    }
    if (finded != nullptr) {
        std::vector<std::string> namesOfNeighbours = getNameNeighboursOnBigBranch(finded, searchName);
        std::cout << "Elf lives next to elves:" << std::endl;
        for (const auto& name : namesOfNeighbours)
            std::cout << name << std::endl;
        std::cout << "Total neighbors:" << namesOfNeighbours.size() << std::endl;
    } else
        std::cout << "There was no elf with that name" << std::endl;
    return 0;
}
