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

class shared_ptr_toy {
    Toy* ptrToy;

    static inline size_t numLinks{}; // Так инициализируется нулем

public:
    shared_ptr_toy(std::string name) {
        ptrToy = new Toy(name);
        numLinks++;
    }

    shared_ptr_toy(const shared_ptr_toy& other) {
        ptrToy = new Toy(other.ptrToy->getName());
        *ptrToy = *other.ptrToy;
        numLinks++;
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other);

    ~shared_ptr_toy() {
        numLinks--;
        if (numLinks == 0)
            delete ptrToy;
    }

    size_t count() const {
        return numLinks;
    }
};

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& other) {
    if (ptrToy != other.ptrToy)
        return *this;
    if (ptrToy)
        delete ptrToy;
    ptrToy = new Toy(other.ptrToy->getName());
    *ptrToy = *other.ptrToy;
    numLinks++;
    return *this;
}

template <typename Arg>
shared_ptr_toy* make_shared_toy (Arg& arg)
{
    return new shared_ptr_toy(arg);
}

int main ()
{
    auto ball1 = make_shared_toy("Ball");
    std::cout << ball1->count() << std::endl;

    auto ball2 = make_shared_toy("Ball");
    std::cout << ball2->count() << std::endl;

    ball2 = ball1;
    std::cout << ball2->count() << std::endl;
    ball2->~shared_ptr_toy();
    std::cout << ball1->count() << std::endl;

    auto ball3 = make_shared_toy(*ball1);
    std::cout << ball3->count() << std::endl;

    return 0;
}
