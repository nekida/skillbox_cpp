#include <iostream>
#include <string>
#include <vector>
#include <memory>

static size_t numCreatToys = 0;

class Toy {
    std::string name;

public:
    Toy(const std::string& name_) : name(name_) {}

    std::string& getName() { return name; }

    ~Toy() {
        std::cout << "Toy " << name << " was dropped" << std::endl;
    }
};

class Dog {
    std::shared_ptr<Toy> toySharedPtr;

public:
    void getToy(std::shared_ptr<Toy> getToySharedPtr) {
        if (getToySharedPtr == nullptr)
            return;
        if (toySharedPtr != nullptr && getToySharedPtr.get()->getName() == toySharedPtr.get()->getName()) {
            std::cout << "I already have this toy" << std::endl;
            return;
        }
        auto num = getToySharedPtr.use_count();
        if (getToySharedPtr.use_count() > numCreatToys) {
            std::cout << "Another dog is playing with this toy" << std::endl;
            return;
        }
        if (toySharedPtr != nullptr)
            toySharedPtr.reset();
        toySharedPtr = getToySharedPtr;
    }

    void dropToy() {
        if (toySharedPtr == nullptr)
            std::cout << "Nothing to drop" << std::endl;
        else
            toySharedPtr.reset();
    }
};

int main ()
{
    Dog dog1, dog2;
    auto toyBall = std::make_shared<Toy>("ball");
    numCreatToys++;
    auto toyBone = std::make_shared<Toy>("bone");
    numCreatToys++;

    dog1.getToy(toyBall);
    dog1.getToy(toyBall);

    std::cout << "----------------------------------------" << std::endl;

    dog2.getToy(toyBone);
    dog1.dropToy();
    dog1.getToy(toyBone);

    std::cout << "----------------------------------------" << std::endl;

    dog2.dropToy();
    dog2.dropToy();
    dog1.getToy(toyBone);

    std::cout << "----------------------------------------" << std::endl;

    return 0;   
}
