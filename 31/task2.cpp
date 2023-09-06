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

namespace My {

static size_t numLinks = 0;

class shared_ptr_toy {
    Toy* ptrToy;

public:
    shared_ptr_toy(std::string& name) {
        ptrToy = new Toy(name);
        numLinks++;
    }

    shared_ptr_toy(const shared_ptr_toy& other) {
        ptrToy = new Toy(*other.ptrToy);
        numLinks++;
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        if (this == &other)
            return *this;
        if (ptrToy != nullptr)
            delete ptrToy;
        ptrToy = new Toy(*other.ptrToy);
        numLinks++;
        return *this;
    }

    ~shared_ptr_toy() {
        numLinks--;
        if (numLinks == 0)
            delete ptrToy;
    }

    size_t count() const {
        return numLinks;
    }
};

}

My::shared_ptr_toy* make_shared_toy (std::string name) // , Toy& toy)
{
    if (name != "") {
        My::shared_ptr_toy* ptrToy = new My::shared_ptr_toy(name);
        return ptrToy;
    }
}

int main ()
{
    std::string name = "Druzhok";
    auto ptr = make_shared_toy("Druzhok");
    std::cout << "Hello" << std::endl;
    return 0;
}
