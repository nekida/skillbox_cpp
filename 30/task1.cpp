#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main ()
{
    std::string cmd;
    do {
        std::cout << "Enter the command: " << std::endl;
        std::cin >> cmd;
        cpr::Response r;

        if (cmd == "get")
            r = cpr::Get(cpr::Url("http://httpbin.org/get"));
        else if (cmd == "post")
            r = cpr::Post(cpr::Url("http://httpbin.org/post"));
        else if (cmd == "put")
            r = cpr::Put(cpr::Url("http://httpbin.org/put"));
        else if (cmd == "delete")
            r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        else if (cmd == "patch")
            r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
        else if (cmd != "exit") {
            std::cout << "Unknown command" << std::endl;
            continue;
        }

        std::cout << r.text << std::endl;
    } while (cmd != "exit");
    return 0;
}
