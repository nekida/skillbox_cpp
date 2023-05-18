#include <iostream>
#include <vector>

void printTwoIndexes (std::vector<int>& v)
{
    int iOne, iTwo, sum;
    iOne = sum = 0;
    iTwo = v.size() - 1;
    for (int i = 0; i < v.size(); ++i)
        sum += v[i];
    for (int i = 0, j = v.size() - 1; i != j; ) {
        if (sum - v[i] > sum) {
            sum -= v[i];
            ++i;
            iOne = i;
        }
        if (sum - v[j] > sum) {
            sum -= v[j];
            --j;
            iTwo = j;
        }
    }
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
