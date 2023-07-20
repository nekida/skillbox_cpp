#include <iostream>
#include <string>
#include <map>

bool isAnagram (std::map<std::string, std::string>& strings)
{
    auto& strKey = strings.begin()->first;
    auto& strVal = strings.begin()->second;
    for (size_t i = 0; i < strKey.length(); ++i) {
        for (size_t j = 0; j < strVal.length(); ++j) {
            if (strKey[i] != strVal[j])
                return false;
        }
    }
    return true;
}

int main ()
{
    std::map<std::string, std::string> strings;
    std::string firstStr, secondStr;
    std::cin >> firstStr >> secondStr;

    strings[firstStr] = secondStr;

    isAnagram(strings) ? std::cout << "true" : std::cout << "false";
    std::cout << std::endl;

    return 0;
}
