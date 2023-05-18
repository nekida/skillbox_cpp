#include <iostream>
#include <vector>

void sorting (std::vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (std::abs (v[i]) < std::abs (v[j])) {
                int t = v[j];
                v[j] = v[i];
                v[i] = t;
            }
        }
    }
}

int main ()
{
    std::cout << "Input size array:" << std::endl;
    int size;
    std::cin >> size;
    std::vector<int> v(size);
    std::cout << "Input elements of array:" << std::endl;
    for (int i = 0; i < size; ++i)
        std::cin >> v[i];
    std::cout << std::endl << "You inputs:" << std::endl << '{';
    for (int i = 0; i < size - 1; ++i)
        std::cout << v[i] << ", ";
    std::cout << v[size - 1] << '}' << std::endl;
    sorting (v);
    std::cout << std::endl << "Result: ";
    for (int i = 0; i < size; ++i) {
        std::cout << v[i];
        if (i < size - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;

    return 0;
}
