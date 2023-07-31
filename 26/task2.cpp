#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

static constexpr int numContacts= 5;

static std::string names[] = { "Anna Ivanova", "Jane Air", "Dima Lakomov", "Boris D.", "Fedor Ivanovich" };
static size_t numbers[] = {+71234567089, +71713456789, +79123555789, +71234646789, +71234956780};


class Contact {
    std::string name;
    size_t number;

public:
    std::string getName() { return name; }
    size_t getNumber() { return number; }
    void setName(std::string contactName) { name = contactName; }
    void setNumber(size_t contactNumber) { number = contactNumber; }
};

class Telephone {
    std::vector<Contact> contacts;

    bool requestNameOrNumber(Contact& contact);

public:
    Telephone();

    void add();

    void call();

    void sms();
};

Telephone::Telephone ()
{
    for (int i = 0; i < numContacts; ++i) {
        Contact contact;
        contact.setName(names[i]);
        contact.setNumber(numbers[i]);
        contacts.push_back(contact);
    }
}

void Telephone::add()
{
    std::cout << "Enter the name of contact" << std::endl;
    std::string name;
    std::getline(std::cin, name); // Пропуск лишнего enter
    std::getline(std::cin, name);
    bool isFinded = false;
    for (auto& contact : contacts) {
        if (name == contact.getName()) {
            std::cout << "A contact with the same name already exists. Set up a new number (y/n)?" << std::endl;
            std::string answer;
            std::cin >> answer;
            if (answer == "y") {
                std::cout << "Enter a new contact number: " << contact.getName() << std::endl;
                size_t newNumber;
                std::cin >> newNumber;
                contact.setNumber(newNumber);
            }
            isFinded = true;
            break;
        }
    }
    if (!isFinded) {
        Contact contact;
        contact.setName(name);
        std::cout << "Enter a contact number: " << contact.getName() << std::endl;
        size_t newNumber;
        std::cin >> newNumber;
        contact.setNumber(newNumber);
        contacts.push_back(contact);
    }
}

bool Telephone::requestNameOrNumber(Contact& contact)
{
    std::string str;
    std::cout << "Enter name or number of the contact: " << std::endl;
    std::getline(std::cin, str); // Пропуск лишнего enter
    std::getline(std::cin, str);
    if (str[1] == '7') {
        int number = stoi(str);
        for (auto& contact_ : contacts) {
            if ((size_t)number == contact_.getNumber()) {
                contact.setNumber(contact_.getNumber());
                contact.setName(contact_.getName());
                return true;
            }
        }
    } else {
        for (auto& contact_ : contacts) {
            if (str == contact_.getName()) {
                contact.setNumber(contact_.getNumber());
                contact.setName(contact_.getName());
                return true;
            }
        }
    }
    std::cout << "No such contact" << std::endl;
    return false;
}

void Telephone::call()
{
    Contact contact;
    if (requestNameOrNumber(contact))
        std::cout << "CALL: " << contact.getNumber() << " " << contact.getName() << std::endl;
}

void Telephone::sms()
{
    Contact contact;
    if (requestNameOrNumber(contact)) {
        std::cout << "Enter the message for " << contact.getName() << ":" << std::endl;
        std::string message;
        getline(std::cin, message, '\n');
        std::cout << "Message sent..." << std::endl;
    }
}

int main ()
{
    Telephone telephone;
    std::cout << "Enter the command" << std::endl;
    std::string cmd;
    std::cin >> cmd;

    while (cmd != "exit") {
        if (cmd == "add")
            telephone.add();
        else if (cmd == "call")
            telephone.call();
        else if (cmd == "sms")
            telephone.sms();
        else
            std::cout << "Unsupported command" << std::endl;

        std::cout << "Enter the command" << std::endl;
        std::cin >> cmd;
    }

    return 0;
}
