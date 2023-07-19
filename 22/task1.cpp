#include <iostream>
#include <string>
#include <map>

struct DataWithStrings {
    std::string input;
    std::string outputNum;
    std::string outputName;
};

bool isSpaceInString (const std::string& str, size_t* pos)
{
    for (*pos = 0; *pos < str.length(); ++*pos)
        if (str[*pos] == ' ')
            return true;
    return false;
}

void getData (DataWithStrings& strings)
{
    size_t pos;
    if (isSpaceInString(strings.input, &pos)) {
        strings.outputNum = strings.input.substr(0, pos);
        strings.outputName = strings.input.substr(pos + 1, strings.input.length() - 1);
    } else if (strings.input[0] >= '0' && strings.input[0] <= '9') {
        strings.outputNum = strings.input;
        strings.outputName = "";
    } else {
        strings.outputNum = "";
        strings.outputName = strings.input;
    }
}

int main ()
{
    std::map<std::string, std::string> NumName;
    std::map<std::string, std::string> NameNum;
    DataWithStrings data;
    getline(std::cin, data.input, '\n');
    getData(data);

    while (data.outputName != "" || data.outputNum != "") {
        if (data.outputName == "")
            std::cout << NumName[data.outputNum] << std::endl;
        else if (data.outputNum == "") {
            for (auto it = NumName.find(NameNum[data.outputName]); it->second == data.outputName; --it) {
                if (it == NumName.begin()) {
                    std::cout << it->first << std::endl;
                    break;
                }
                std::cout << it->first << ' ';
            }
        }
        else {
            NumName[data.outputNum] = data.outputName;
            NameNum[data.outputName] = data.outputNum;
        }

        getline(std::cin, data.input, '\n');
        getData(data);
    }

    return 0;
}
