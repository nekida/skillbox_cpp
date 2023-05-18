#include <iostream>
#include <vector>

void sorting (std::vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (v[i] < v[j]) {
                int t = v[j];
                v[j] = v[i];
                v[i] = t;
            }
        }
    }
}

int main ()
{
    std::cout << "Input values" << std::endl;
    std::vector<int> v(0);
    int val = 0;
    while (val != -2) {
        std::cin >> val;
        if (val == -1) {
            if (v.size() < 5)
                std::cout << "No 5 items" << std::endl;
            else {
                sorting (v);
                std::cout << "Result: " << v[4] << std::endl;
            }
            continue;
        }
        v.push_back(val);
    }
    std::cout << "Program completion" << std::endl;

    return 0;
}
