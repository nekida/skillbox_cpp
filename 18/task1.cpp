#include <iostream>
#include <vector>

void swapvec (std::vector<int>& v, int *a)
{
    for (size_t i = 0; i < v.size (); ++i) {
        int t = v[i];
        v[i] = a[i];
        a[i] = t;
    }
}

void print (int *p, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
}

int main ()
{
    std::cout << "Input sizes of vector and array: " << std::endl;
    int n;
    std::cin >> n;
    int array[n];
    std::vector<int> vec (n);

    std::cout << "Input " << n << " values of vector: " << std::endl;
    for (int i = 0; i < n; i++)
        std::cin >> vec[i];
    std::cout << "Input " << n << " values of array: " << std::endl;
    for (int i = 0; i < n; i++)
        std::cin >> array[i];

    std::cout << std::endl << "You input" << std::endl;
    std::cout << "Vector: ";
    print (&vec[0], n);
    std::cout << "Array: ";
    print (&array[0], n);

    std::cout << std::endl << "Swap" << std::endl;
    swapvec (vec, array);

    std::cout << std::endl << "Result" << std::endl;
    std::cout << "Vector: ";
    print (&vec[0], n);
    std::cout << "Array: ";
    print (&array[0], n);

    return 0;
}
