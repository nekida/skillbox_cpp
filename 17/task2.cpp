#include <iostream>

void reverseArray (int *a)
{
    for (int i = 0, j = 9; i < 5; i++, j--) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main ()
{
    std::cout << "Input 10 numbers" << std::endl;
    int a[10];
    for (int i = 0; i < 10; i++)
        std::cin >> a[i];
    reverseArray (a);
    for (int i = 0; i < 10; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;

    return 0;
}
