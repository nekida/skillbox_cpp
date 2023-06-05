#include <iostream>
#include <fstream>
#include <string>

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
    char buf[10];
    while (!file.eof()) {
        file.read(buf, sizeof (buf));
        auto size = file.gcount();
        if ((long unsigned int)size < sizeof (buf))
            buf[size] = '\0';
        std::cout << buf;
    }
    file.close();

    return 0;
}
