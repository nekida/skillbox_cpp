#include <iostream>
#include <string>
#include <vector>

template <typename T1, typename T2>
struct Pair {
    T1 key;
    T2 value;
};

template <typename T1, typename T2>
std::vector<Pair<T1, T2>> base;

template <typename T1, typename T2>
Pair<T1, T2> add(void)
{
    std::cout << "Input key and value" << std::endl;
    T1 key;
    T2 value;
    std::cin >> key >> value;
    Pair pair(key, value);
    base.push_back(pair);
    return pair;
}

int main ()
{
    std::string cmd;
    std::cin >> cmd;
    while (cmd != "quit") {
        if (cmd == "add") {
            Pair pair = add();
        }
    }
    

    return 0;
}
