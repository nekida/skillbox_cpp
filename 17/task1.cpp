#include <iostream>

void mySwap (int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main ()
{
    std::cout << "Input two numbers" << std::endl;
    int a, b;
    std::cin >> a >> b;
    mySwap (&a, &b);
    std::cout << a << ' ' << b << std::endl;

    return 0;
}
