#include <iostream>
#include <fstream>
#include <string>

bool checkExtension (std::string& str)
{
    return !str.compare ("png") || !str.compare ("PNG");
}

int main ()
{
    std::cout << "Enter file path" << std::endl;
    std::string path;
    std::cin >> path;

    std::ifstream file;
    file.open(path, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error open file" << std::endl;
        return 0;
    }

    std::string str;
    file >> str;
    file.close();

    std::string start = str.substr (1, 3);
    std::string end = path.substr (path.size() - 3, 3);
    bool res = (str[0] == -119) && checkExtension (start) && checkExtension (end);

    res ? std::cout << "File is .PNG" : std::cout << "File is not .PNG";
    std::cout << std::endl;

    return 0;
}
