#include <iostream>

void evendigits (long long n, int& ans)
{
    if (n % 10 % 2 == 0)
        ans++;
    if (n > 10)
        evendigits (n / 10, ans);
}

int main ()
{
    std::cout << "Input long long num" << std::endl;
    long long n;
    int k = 0;
    std::cin >> n;
    evendigits (n, k);
    std::cout << k << std::endl;
    return 0;
}
