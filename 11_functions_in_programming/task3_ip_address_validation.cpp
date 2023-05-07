#include <iostream>
#include <string>

std::string get_address_part (std::string address, unsigned part)
{
    std::string str;
    if (part > 3)
        return str;
    unsigned len = address.length();
    unsigned counterDots = 0;
    for (unsigned i = 0, counterNums = 0; i < len; ++i) {
        if (address[i] >= '0' && address[i] <= '9')
            counterNums++;
        else if (address[i] == '.') {
            if (counterNums == 0)
                return str;
            else
                counterNums = 0;
            counterDots++;
        } else
            return str;
    }
    if (counterDots != 3)
        return str;
    counterDots = 0;
    for (unsigned i = 0; i < len; ++i) {
        if (address[i] == '.')
            counterDots++;
        else if (counterDots == part)
            str.push_back (address[i]);
    }
    return str;
}

bool check_part (std::string address, unsigned part)
{
    std::string str;
    str = get_address_part (address, part);
    unsigned len = str.length ();
    if (len == 0 || len > 3)
        return false;
    if (len == 2 && str[0] == '0')
        return false;
    else if (len == 3) {
        if ((str[0] == '0') || (str[0] == '0' && str[1] == '0') || str[0] > '2' ||
                (str[0] > '2' && str[1] > '5') ||
                        (str[0] >= '2' && str[1] >= '5' && str[2] > '5'))
            return false;
    }
    return true;
}

bool check_ip (std::string address)
{
    for (unsigned i = 0; i < 4; ++i)
        if (!check_part (address, i))
            return false;
    return true;
}

int main ()
{
    std::cout << "Input the IP address" << std::endl;
    std::string addr;
    std::cin >> addr;
    check_ip (addr) ? std::cout << "Valid" : std::cout << "Invalid";
    std::cout << std::endl;
    return 0;
}
