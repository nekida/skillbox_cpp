#include <iostream>
#include <vector>
#include <string>

template <typename T1, typename T2>
struct Pair {
    T1 key;
    T2 value;
};

template <typename T1, typename T2>
void commandControl(std::vector<Pair<T1, T2>>& v)
{
    std::cout << "Input the command " << std::endl;
    std::string cmd;
    std::cin >> cmd;
    while (cmd != "exit") {
        if (cmd == "add") {
            T1 key;
            T2 value;
            std::cout << "Input the key and the value " << std::endl;
            std::cin >> key >> value;
            v.push_back({key, value});
        } else if (cmd == "remove") {
            if (v.empty())
                std::cout << "Vector is empty " << std::endl;
            std::cout << "Input the key " << std::endl;
            T1 key;
            std::cin >> key;
            bool found = false;
            for (int i = 0; i < v.size(); i++) {
                if (v[i].key == key) {
                    v.erase(v.begin() + i);
                    found = true;
                }
            }
            if (!found)
                std::cout << "Not found this key " << std::endl;
        } else if (cmd == "print") {
            if (v.empty())
                std::cout << "Vector is empty " << std::endl;
            for (const auto& pair : v) {
                std::cout << pair.key << " - " << pair.value << std::endl;
            }
        } else if (cmd == "find") {
            if (v.empty())
                std::cout << "Vector is empty " << std::endl;
            std::cout << "Input the key " << std::endl;
            T1 key;
            std::cin >> key;
            bool found = false;
            for (const auto& pair : v) {
                if (pair.key == key) {
                    std::cout << pair.value << std::endl;
                    found = true;
                }
            }
            if (!found)
                std::cout << "Not found this key " << std::endl;
        }

        std::cout << "Input the command " << std::endl;
        std::cin >> cmd;
    }
}

int main ()
{
    std::cout << "Input type of key and type of value" << std::endl;
    std::string typeKey, typeValue;
    std::cin >> typeKey >> typeValue;
    if (typeKey == "int" && typeValue == "int") {
        std::vector<Pair<int, int>> vecIntInt;
        commandControl(vecIntInt);
    } else if (typeKey == "int" && typeValue == "double") {
        std::vector<Pair<int, double>> vecIntDouble;
        commandControl(vecIntDouble);
    } else if (typeKey == "int" && typeValue == "string") {
        std::vector<Pair<int, std::string>> vecIntStr;
        commandControl(vecIntStr);
    } else if (typeKey == "double" && typeValue == "double") {
        std::vector<Pair<double, double>> vecDoubleDouble;
        commandControl(vecDoubleDouble);
    } else if (typeKey == "double" && typeValue == "int") {
        std::vector<Pair<double, int>> vecDoubleInt;
        commandControl(vecDoubleInt);
    } else if (typeKey == "double" && typeValue == "string") {
        std::vector<Pair<double, std::string>> vecDoubleStr;
        commandControl(vecDoubleStr);
    } else if (typeKey == "string" && typeValue == "double") {
        std::vector<Pair<std::string, double>> vecStrDouble;
        commandControl(vecStrDouble);
    } else if (typeKey == "string" && typeValue == "int") {
        std::vector<Pair<std::string, int>> vecStrInt;
        commandControl(vecStrInt);
    } else if (typeKey == "string" && typeValue == "string") {
        std::vector<Pair<std::string, std::string>> vecStrStr;
        commandControl(vecStrStr);
    }

    return 0;
}
