#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct person {
    std::string firstName;
    std::string lastName;
    std::string date;
    unsigned int sum;
};

bool openFile (std::ifstream& file)
{
    file.open ("sheet.bin", std::ios_base::binary);
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
    std::vector<person> persons(1);

    while (!sheet.eof() && persons.back().firstName != "") {
        
    }

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

    } else
        std::cout << "Unsupported command" << std::endl;

    return 0;
}
