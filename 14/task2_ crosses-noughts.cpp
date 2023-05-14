#include <iostream>

void printField (char field[][3])
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            std::cout << field[i][j] << ' ';
        std::cout << std::endl;
    }
}

char checkDiag (char field[][3])
{
    if (field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X')
        return 'X';
    else if (field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O')
        return 'O';
    else if (field[0][2] == 'O' && field[1][1] == 'O' && field[2][0] == 'O')
        return 'O';
    else if (field[0][2] == 'X' && field[1][1] == 'X' && field[2][0] == 'X')
        return 'X';
    else
        return ' ';
}

char checkColumn (char field[][3])
{
    int cntCross, cntNough;
    cntCross = cntNough = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (field[j][i] == 'X')
                cntCross++;
            else if (field[j][i] == 'O')
                cntNough++;
        }
        if (cntCross == 3)
            return 'X';
        else if (cntNough == 3)
            return 'O';
        else
            cntCross = cntNough = 0;            
    }
    return ' ';
}

char checkRow (char field[][3])
{
    int cntCross, cntNough;
    cntCross = cntNough = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (field[i][j] == 'X')
                cntCross++;
            else if (field[i][j] == 'O')
                cntNough++;
        }
        if (cntCross == 3)
            return 'X';
        else if (cntNough == 3)
            return 'O';
        else
            cntCross = cntNough = 0;            
    }
    return ' ';
}

char checkField (char field[][3])
{
    char ch = checkRow (field);
    if (ch != ' ')
        return ch;
    ch = checkColumn (field);
    if (ch != ' ')
        return ch;
    ch = checkDiag (field);
    if (ch != ' ')
        return ch;
    return ' ';
}

bool setSymbol(char field[][3], bool state[][3], int x, int y, char ch)
{
    if (x < 1 || x > 3 || y < 1 || y > 3) {
        std::cout << "incorrect values" << std::endl;
        return false;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == x - 1 && j == y - 1) {
                if (state[i][j] == false) {
                    field[i][j] = ch;
                    state[i][j] = true;
                    return true;
                } else {
                    std::cout << "coordinates is not empty. Repeat input" << std::endl;
                    return false;
                }
            }
        }
    }
}

int main ()
{
    char gameField[3][3] = {
        {' ', ' ', ' ',},
        {' ', ' ', ' ',},
        {' ', ' ', ' ',}
    };

    bool stateField[3][3] = {
        {false, false, false,},
        {false, false, false,},
        {false, false, false,}
    };

    char symbol, winSymbol;
    symbol = 'X';
    winSymbol = checkField(gameField);
    int cntSteps = 0;
    while (cntSteps < 9 && winSymbol == ' ') {
        std::cout << "input coordinate (x, y, 1..3)" << std::endl;
        int coorX, coorY;
        std::cin >> coorX >> coorY;
        if (!setSymbol(gameField, stateField, coorX, coorY, symbol))
            continue;
        printField(gameField);
        if (symbol == 'X')
            symbol = 'O';
        else
            symbol = 'X';
        cntSteps++;
        winSymbol = checkField(gameField);
    }

    if (cntSteps == 9)
        std::cout << "draw" << std::endl;
    else if (winSymbol == 'X')
        std::cout << "X win" << std::endl;
    else if (winSymbol == 'O')
        std::cout << "O win" << std::endl;

    return 0;
}
