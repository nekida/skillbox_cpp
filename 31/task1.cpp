#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Toy {
    std::string name;

public:
    Toy(const std::string& name_) : name(name_) {}

    std::string getName() const { return name; }

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
        if (getToySharedPtr.get()->getName() == toySharedPtr.get()->getName()) {
            std::cout << "I already have this toy" << std::endl;
            return;
        }
        if (getToySharedPtr.use_count() > 1) {
            std::cout << "Another dog is playing with this toy" << std::endl;
            return;
        }
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
    Toy toy("noName");
    std::cout << "Hello" << std::endl;
    return 0;
}
