#include <iostream>
#include <string>
#include <vector>

class Talent {
public:
    virtual std::string getName() = 0;
};

class Swimming : virtual public Talent {
public:
    std::string getName() { return "Swim"; }
};

class Dancing : virtual public Talent {
public:
    std::string getName() { return "Dance"; }
};

class Counting : virtual public Talent {
public:
    std::string getName() { return "Count"; }
};

class Dog {
    std::string name;

    std::vector<Talent*> talents;

public:
    Dog(std::string inName) : name(inName) {}

    void addTalent(Talent* talent) { talents.push_back(talent); }

    void showTalents() {
        std::cout << "This is " << name << " and it has some talents:" << std::endl;
        for (size_t i = 0; i < talents.size(); ++i)
            std::cout << "It can \"" << talents[i]->getName() << "\"" << std::endl;
    }
};

int main ()
{
    Dog dog1("Steve");
    class Dancing dance;
    class Swimming swim;
    dog1.addTalent(&dance);
    dog1.addTalent(&swim);
    dog1.showTalents();

    return 0;
}
