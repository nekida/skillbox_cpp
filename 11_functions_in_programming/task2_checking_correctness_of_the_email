#include <iostream>
#include <string>

constexpr unsigned int maxLenFirstPart = 64;
constexpr unsigned int maxLenSecondPart = 63;

std::string strDictFisrtPart = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!#$%&'*+-/=?^_`{|}~";
std::string strDictSeconfPart = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890-";

std::string getFirstPartAddr (std::string email)
{
    std::string str;
    for (unsigned int i = 0; email[i] != '@'; ++i)
        str.push_back (email[i]);
    return str.length () == email.length () ? "" : str;
}

std::string getSecondPartAddr (std::string email)
{
    unsigned int i = 0;
    while (email[i] != '@')
        ++i;
    ++i;
    unsigned len = email.length ();
    std::string str;
    if (i >= len)
        return str;
    for (; i < len; ++i)
        str.push_back (email[i]);
    return str;
}

bool checkEmailAddressParts (std::string part, std::string dict, unsigned maxSize)
{
    unsigned len = part.length ();
    if (len < 1 || len > maxSize || part[0] == '.' || part[len - 1] == '.')
        return false;
    bool isDot = false;
    for (unsigned i = 0; i < len; ++i) {
        if (part[i] == '.' && !isDot) {
            isDot = true;
            continue;
        } else if (part[i] == '.' && isDot)
            return false;
        else
            isDot = false;
        bool isFound = false;
        for (unsigned j = 0; j < dict.length (); ++j) {
            if (part[i] == dict[j]) {
                isFound = true;
                break;
            }
        }
        if (!isFound)
            return false;
    }
    return true;
}

int main ()
{
    std::cout << "Input the email address:" << std::endl;
    std::string email, firstPart, secondPart;
    std::cin >> email;
    firstPart = getFirstPartAddr (email);
    if (!checkEmailAddressParts (firstPart, strDictFisrtPart, maxLenFirstPart)) {
        std::cout << "No" << std::endl;
        return 0;
    }
    secondPart = getSecondPartAddr (email);
    if (!checkEmailAddressParts (secondPart, strDictSeconfPart, maxLenSecondPart)) {
        std::cout << "No" << std::endl;
        return 0;
    }
    std::cout << "Yes" << std::endl;
    return 0;
}
