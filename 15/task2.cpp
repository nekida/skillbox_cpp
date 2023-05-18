#include <iostream>
#include <vector>

void printTwoNum (std::vector<int>& v, int sum)
{
    int size = v.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if ((v[i] + v [j]) == sum) {
                std::cout << std::endl << "Result: " << v[i] << " " << v[j] << std::endl;
                return;
            }
        }
    }
    std::cerr << "No pair of numbers" << std::endl;
}

int main ()
{
    std::cout << "Input size of array" << std::endl;
    int size;
    std::cin >> size;
    std::vector<int>v(size);

    std::cout << "Input " << size << " elements of array" << std::endl;
    for (int i = 0; i < size; ++i)
        std::cin >> v[i];

    std::cout << std::endl << "You input:" << std::endl << '{';
    for (int i = 0; i < size - 1; ++i) {
        std::cout << v[i] << ", ";
    }
    std::cout << v[v.size() - 1] << '}' << std::endl;

    std::cout << std::endl << "Input sum value:" << std::endl;
    int sum;
    std::cin >> sum;

    printTwoNum(v, sum);
    return 0;
}
