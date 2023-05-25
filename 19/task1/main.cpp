#include <iostream>
#include <fstream>
#include <string>

int main ()
{
    std::cout << "Input word for searching:" << std::endl;
    std::string word;
    std::cin >> word;
    int counter = 0;

    std::ifstream file;
    file.open("words.txt");
    while (!file.eof()) {
        std::string temp;
        file >> temp;
        if (temp == word)
            counter++;
    }
    file.close();

    std::cout << "In file \"words.txt\" " << counter << " words \"" << word << "\"" << std::endl;
}
