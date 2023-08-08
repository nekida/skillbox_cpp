#include <iostream>
#include <string>
#include <random>

class Person {
    std::string name;

public:
    std::string& getName() { return name; }
};

class CEO : public Person {
public:
    void setCommand(class Manager& manager, int command) {
        manager.setCommand(command);
    }
};

class Worker : public Person {

};

class Manager : public Person {
    int serialNumber = 0;

    int command = 0;

public:
    void setSerialNumber(int inSerialNumber) { serialNumber = inSerialNumber; }

    void setCommand(int inCommand) { command = inCommand; }

    int getNumTasks(int inNumWorkers) {
        std::srand(serialNumber + command);
        return rand() % (inNumWorkers + 1);
    }
};

class Band {
    Manager manager;

    Worker *workers = nullptr;

    int numWorkers = 0;

    int numTasks = 0;

public:
    void setNumWorkers(int inNumWorkers)
    {
        numWorkers = inNumWorkers;
        workers = new Worker[numWorkers];
    }

    Worker* getWorkers() { return workers; }

    Manager& getManager() { return manager; }

    int getNumWorkers() const { return numWorkers; }
};

class Company {
    CEO ceo;

    Band *bands = nullptr;

    int numBands = 0;

public:
    void setNumBands(int inNumBands)
    {
        numBands = inNumBands;
        bands = new Band[numBands];
    }

    Band* getBands() { return bands; }

    CEO& getCEO() { return ceo; }

    int getNumBands() const { return numBands; }
};

int main ()
{
    Company company;
    std::cout << "Enter name of CEO company" << std::endl;
    std::cin >> company.getCEO().getName();
    std::cout << "Enter number of bands: " << std::endl;
    int numBands;
    std::cin >> numBands;
    company.setNumBands(numBands);
    for (int i = 0; i < numBands; ++i) {
        std::cout << "Enter number of workers in bands " << i << std::endl;
        int numWorkers;
        std::cin >> numWorkers;
        company.getBands()[i].setNumWorkers(numWorkers);
        for (int j = 0; j < numWorkers; ++j) {
            std::cout << "Enter name of worker " << j << std::endl;
            std::cin >> company.getBands()[i].getWorkers()[j].getName();
        }
        std::cout << "Enter name of manager in bands " << i << std::endl;
        std::cin >> company.getBands()[i].getManager().getName();
        company.getBands()[i].getManager().setSerialNumber(i + 1);
    }

    return 0;
}
