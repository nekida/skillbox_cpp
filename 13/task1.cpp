#include <iostream>
#include <vector>

int main ()
{
    int inSize, numDel;
    std::cout << "Input vector size: ";
    std::cin >> inSize;
    std::vector<int> v(inSize);
    std::cout << "Input numbers: ";
    for (int i = 0; i < inSize; ++i) {
        int num;
        std::cin >> num;
        v[i] = num;
    }
    std::cout << "Input number to delete: ";
    std::cin >> numDel;
    for (int i = 0; i < v.size(); ++i) {
        if (numDel == v[i]) {
            int t = v[i];
            for (int j = i; j < v.size() - 1; ++j)
                v[j] = v[j + 1];
            v[v.size() - 1] = t;
            v.pop_back();
            --i;
        }
    }
    std::cout << "Result: ";
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";

    return 0;
}
