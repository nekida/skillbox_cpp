#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Person {
    std::string firstName;
    std::string lastName;
    std::string date;
    unsigned int sum;
};

template <typename TypeStream>
bool openFile (TypeStream& file)
{
    file.open ("sheet.bin", std::ios_base::binary | std::ofstream::app);
    if (!file.is_open()) {
        std::cout << "Error open file sheet.bin" << std::endl;
        return false;
    }
    return true;
}

void commandList ()
{
    std::ifstream sheet;
    if (!openFile (sheet))
        return;

    std::vector<Person> persons;
    while (!sheet.eof()) {
        Person person;
        sheet >> person.firstName;
        if (sheet.eof())
            break;
        sheet >> person.lastName >> person.date >> person.sum;
        persons.push_back(person);
    }

    sheet.close ();

    for (size_t i = 0; i < persons.size(); ++i)
        std::cout << persons[i].firstName << ' ' << persons[i].lastName << ' ' << persons[i].date << ' ' << persons[i].sum << std::endl;
}

void commandAdd ()
{
    Person person;

    std::cout << "Enter first name, last name, date (dd.mm.yyyy) and summary:" << std::endl;
    std::cin >> person.firstName >> person.lastName >> person.date >> person.sum;

    std::ofstream sheet;
    if (!openFile (sheet))
        return;

    sheet << person.firstName << ' ' << person.lastName << ' ' << person.date << ' ' << person.sum << std::endl;

    sheet.close ();
}

int main ()
{
    std::cout << "Enter the command (list/add):" << std::endl;
    std::string command;
    std::cin >> command;

    if (command == "list") {
        commandList ();
    } else if (command == "add") {
        commandAdd();
    } else
        std::cout << "Unsupported command" << std::endl;

    return 0;
}
