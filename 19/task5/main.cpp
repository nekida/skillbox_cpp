#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

static bool isUse[13];

int getNumQuestions (int offset)
{
    if (offset > 13)
        offset %= 13;
    if (offset > 0)
        --offset;
    for (int i = offset; i < 13; i++)
        if (!isUse[i]) {
            isUse[i] = true;
            return i;
        }
    for (int i = 0; i < offset; i++)
        if (!isUse[i]) {
            isUse[i] = true;
            return i;
        }
    return 0;
}

std::string getStr (std::string path, int offset)
{
    std::ifstream file;
    file.open(path, std::ios::binary);
    std::string str;
    int numInFile = 0;
    while (std::getline (file, str) && numInFile != offset) {
        ++numInFile;
    }
    file.close();
    return (numInFile > offset) ? "" : str;
}

int main ()
{
    std::cout << "Enter the path to the file with questions" << std::endl;
    std::string pathQuestions;
    std::cin >> pathQuestions;

    std::cout << "Enter the path to the file with the answers" << std::endl;
    std::string pathAnswers;
    std::cin >> pathAnswers;

    int cntSpectators, cntConnoisseurs;
    cntSpectators = cntConnoisseurs = 0;
    int offset = 0;
    while (cntSpectators < 6 && cntConnoisseurs < 6) {
        std::cout << "<-------------Score------------->" << std::endl;
        std::cout << "Spectators: " << cntSpectators << std::endl;
        std::cout << "Connoisseurs: " << cntConnoisseurs << std::endl;
        std::cout << "<------------------------------->" << std::endl;
        std::cout << "Enter offset value:" << std::endl;
        int inputOffset;
        std::cin >> inputOffset;
        if (inputOffset < 1) {
            std::cout << "Incorrect value. Repeat" << std::endl;
            continue;
        }
        offset += inputOffset;
        int num = getNumQuestions (offset);
        std::string question = getStr (pathQuestions, num);
        if (question.empty ()) {
            std::cout << "Error read!" << std::endl;
            return 0;
        }
        std::cout << "Question: " << question << std::endl;
        std::cout << "Input answer" << std::endl;
        std::string answerIn;
        std::cin >> answerIn;
        if (answerIn == getStr (pathAnswers, num)) {
            cntConnoisseurs++;
            std::cout << "Right answer" << std::endl;
        } else {
            cntSpectators++;
            std::cout << "Wrong answer" << std::endl;
        }
    }

    cntSpectators == 6 ? std::cout << "Spectators" : std::cout << "Connoisseurs";
    std::cout << " win!" << std::endl;

    return 0;
}
