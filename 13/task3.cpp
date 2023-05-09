#include <iostream>
#include <vector>

int main ()
{
    constexpr int maxElements = 20;
    std::vector<int> v(maxElements);
    int head, inputNum;
    bool isFull = false;
    head = inputNum = 0;
    std::cout << "input number: ";
    std::cin >> inputNum;
    while (inputNum != -1) {
        v[head++] = inputNum;
        if (head == maxElements) {
            head = 0;
            isFull = true;
        }
        std::cout << "input number: ";
        std::cin >> inputNum;
    }
    std::cout << "output: ";

    if (isFull) {
        for (int i = head; i < v.size(); ++i)
            std::cout << v[i] << " ";
        for (int i = 0; i < head; ++i)
            std::cout << v[i] << " ";
    } else 
        for (int i = 0; i < head; ++i)
            std::cout << v[i] << " ";
    return 0;
}
