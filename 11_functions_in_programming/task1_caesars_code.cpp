#include <iostream>
#include <string>

constexpr int numAlphabet = 26;

std::string encrypt_caesar (std::string str, int num)
{
    constexpr int alphaStartBig = 65;
    constexpr int alphaStartLittle = 97;
    int offset = num % numAlphabet;
    for (uint i = 0; i < str.length (); i++) {
        int alphaStart;
        if (str[i] >= 'A' && str[i] <= 'Z')
            alphaStart = alphaStartBig;
        else if (str[i] >= 'a' && str[i] <= 'z')
            alphaStart = alphaStartLittle;
        else {
            continue;
        }
        str[i] -= alphaStart;
        str[i] = ((str[i] + offset) >= numAlphabet) ? (str[i] + offset) % numAlphabet : str[i] + offset;
        str[i] += alphaStart;
    }
    return str;
}

std::string decrypt_caesar (std::string str, int num)
{
    return encrypt_caesar (str, numAlphabet - num);
}

int main ()
{
    std::cout << "Введите фразу для кодирования шифром Цезаря:" << std::endl;
    std::string strCode, strDecode;
    std::getline (std::cin, strCode);
    std::cout << "Введите значение для сдвига:" << std::endl;
    int offsetCode, offsetDecode;
    std::cin >> offsetCode;
    std::cout << encrypt_caesar (strCode, offsetCode) << std::endl;

    // Для исключения лишнего пробела
    std::string tmp;
    std::getline (std::cin, tmp);

    std::cout << "Введите фразу для декодирования шифра Цезаря:" << std::endl;
    std::getline (std::cin, strDecode);
    std::cout << "Введите значение для сдвига:" << std::endl;
    std::cin >> offsetDecode;
    std::cout << decrypt_caesar (strDecode, offsetDecode) << std::endl;

    return 0;
}
