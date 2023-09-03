#include <iostream>
#include <string>
#include <cpr/cpr.h>

std::string getContent(const std::string& content, const std::string& m1, const std::string& m2)
{
    return content.substr(content.find(m1) + m1.length(), content.find(m2) - content.rfind(m1) - m1.length());
}

int main ()
{
    cpr::Response r;
    r = cpr::Get(cpr::Url("http://httpbin.org/html"));
    std::cout << "Header: " << getContent(r.text, "<h1>", "</h1>") << std::endl;

    return 0;
}
