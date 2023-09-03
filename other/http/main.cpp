#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main ()
{
    std::string firstName, lastName, city;
    std::cout << "Enter first name: " << std::endl;
    std::cin >> firstName;
    std::cout << "Enter last name: " << lastName << std::endl;
    std::cin >> lastName;
    std::cout << "Enter city: " << city << std::endl;
    std::cin >> city;
    cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                cpr::Payload({{"first name", firstName.c_str()},
                                                {"last name", lastName.c_str()},
                                                {"city", city.c_str()}}));
    std::cout << r.text << std::endl;
    return 0;
}
