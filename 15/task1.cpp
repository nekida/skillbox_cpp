#include <iostream>
#include <vector>

void printTwoIndexes (std::vector<int>& v)
{
    int iOne, iTwo, sum, prevSum, size;
    prevSum = 0;
    size = v.size();
    for (int i = 0; i < size; ++i) {
        sum = v[i];
        for (int j = 1 + i; j < size; ++j) {
            sum += v[j];
            if (sum > prevSum) {
                prevSum = sum;
                iOne = i;
                iTwo = j;
            }
        }
    }
    std::cout << "Result: " << iOne << ' ' << iTwo << std::endl;
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
    printTwoIndexes (v);
    return 0;
}
