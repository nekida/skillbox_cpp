#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

int main ()
{
    auto uniqNums = [](std::vector<int>& v) {
        std::unordered_set<int> uSet(v.begin(), v.end());
        return std::make_unique<std::vector<int>>(uSet.begin(), uSet.end());
    };

    std::cout << "Enter the number of numbers you want to enter" << std::endl;
    size_t num;
    std::cin >> num;
    std::vector<int> inputNums;
    for (size_t i = 0; i < num; i++) {
        std::cout << "Enter the " << i + 1 << " number" << std::endl;
        int input;
        std::cin >> input;
        inputNums.push_back(input);
    }

    auto res = uniqNums(inputNums);

    std::cout << "Unique numbers:" << std::endl;
    for (const auto& num : *res) {
        std::cout << num << " ";
    }

    return 0;
}
