#include <iostream>
#include <string>
#include <random>

class Person {
    std::string name;

public:
    std::string& getName() { return name; }
};

class Worker : public Person {

};

class Manager : public Person {
    int serialNumber = 0;

    int command = 0;

    int getNumTasks(int num) {
        std::srand(serialNumber + command);
        return rand() % (num + 1);
    }

    char getTypeTask() {
        int i = (rand() % (3));
        char types[] = { 'A', 'B', 'C' };
        return types[i];
    }

public:
    void setSerialNumber(int inSerialNumber) { serialNumber = inSerialNumber; }

    void setCommandFromCEO(int inCommand) {
        command = inCommand;
        std::cout << "Manager " << getName()<< " started to complete the task " << command << std::endl;
    }

    void setCommandToWorker(int inNumWorkers, Worker* workers) {
        int numTasks = getNumTasks(inNumWorkers);
        if (numTasks > inNumWorkers) numTasks = inNumWorkers;
        if (numTasks == 0) numTasks = 1;
        for (int i = 0; i < numTasks; ++i) {
            std::cout << "Worker " << workers[i].getName() << " started to complete the task " << command << " type of " << getTypeTask() << std::endl;
        }
    }
};

class CEO : public Person {
public:
    void setCommand(class Manager& manager, int command) {
        manager.setCommandFromCEO(command);
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
    for (int i = 0; i < company.getNumBands(); ++i) {
        std::cout << "Enter number of workers in bands " << i + 1 << std::endl;
        int numWorkers;
        std::cin >> numWorkers;
        company.getBands()[i].setNumWorkers(numWorkers);
        for (int j = 0; j < company.getBands()[i].getNumWorkers(); ++j) {
            std::cout << "Enter name of worker " << j + 1 << std::endl;
            std::cin >> company.getBands()[i].getWorkers()[j].getName();
        }
        std::cout << "Enter name of manager in bands " << i + 1 << std::endl;
        std::cin >> company.getBands()[i].getManager().getName();
        company.getBands()[i].getManager().setSerialNumber(i + 1);
    }

    std::cout << "You is CEO. Let's start command" << std::endl;
    for (int i = 0; i < company.getNumBands(); ++i) {
        std::cout << "Enter command for manager from band " << i + 1 << std::endl;
        int command;
        std::cin >> command;
        company.getCEO().setCommand(company.getBands()[i].getManager(), command);
        company.getBands()[i].getManager().setCommandToWorker(company.getBands()[i].getNumWorkers(), company.getBands()[i].getWorkers());
    }

    return 0;
}
