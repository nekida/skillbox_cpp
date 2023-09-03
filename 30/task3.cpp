#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>

void sendPost (const std::vector<std::string>& params)
{
    if (params.size() % 2 != 0 || params.empty()) {
        std::cout << "Bad params" << std::endl;
        return;
    }
    std::vector<cpr::Pair> pairs;
    for (size_t i = 0; i < params.size() - 1; i += 2)
        pairs.push_back({params[i], params[i + 1]});
    cpr::Payload payload(pairs.begin(), pairs.end());
    std::cout << cpr::Post(cpr::Url("http://httpbin.org/post"), payload).text << std::endl;
}

void sendGet (const std::vector<std::string>& params)
{
    if (params.size() % 2 != 0 || params.empty()) {
        std::cout << "Bad params" << std::endl;
        return;
    }
    std::string str = "http://httpbin.org/get?";
    for (size_t i = 0; i < params.size() - 1; i += 2)
        str += params[i] + '=' + params[i + 1] + '&';
    str.resize(str.size() - 1); // delete last '&'
    std::cout << cpr::Get(cpr::Url(str)).text << std::endl;
}

int main ()
{
    std::string inputStr;
    std::vector<std::string> argsAndValues;
    do {
        std::cin >> inputStr;
        if (inputStr == "post")
            sendPost(argsAndValues);
        else if (inputStr == "get")
            sendGet(argsAndValues);
        else
            argsAndValues.push_back(inputStr);
    } while (inputStr != "post" && inputStr != "get");

    return 0;
}
