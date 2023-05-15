#include <iostream>

static constexpr int sizeField = 10;

void printFields (char matrix[][sizeField])
{
    std::cout << "   ";
    for (int i = 0; i < sizeField; ++i)
        std::cout << i << ' ';
    std::cout << std::endl;
    for (int i = 0; i < sizeField; ++i) {
        std::cout << i << "  ";
        for (int j = 0; j < sizeField; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool checkCorrectValue (int x, int y)
{
    if (x < 0 || x > 9 || y < 0 || y > 9) {
        std::cout << "incorrect values. repeat" << std::endl;
        return false;
    }
    return true;
}

void setShip (char field[][sizeField], int x, int y)
{
    field[x][y] = 'O';
}

bool checkShipOne (char field[][sizeField], int x, int y)
{
    return field[x][y] == 'O';
}

bool checkShipSome (char field[][sizeField], int x1, int y1, int x2, int y2)
{
    if (y1 == y2) {
        for (int i = x1; i <= x2; ++i)
            if (!checkShipOne(field, i, y1))
                return false;
    } else if (x1 == x2) {
        for (int i = y1; i <= y2; ++i)
            if (!checkShipOne(field, x1, i))
                return false;
    }
    return true;
}

void fillingShipOne (char field[][sizeField])
{
    int counter = 4;
    while (counter) {
        std::cout << "ships left " << counter << std::endl;
        std::cout << "enter one coordinate (x, y)" << std::endl;
        int x, y;
        std::cin >> x >> y;
        if (!checkCorrectValue(x, y)) {
            std::cout << "incorrect values. repeat" << std::endl;
            continue;
        }
        if (checkShipOne(field, x, y)) {
            std::cout << "seat is taken. repeat" << std::endl;
            continue;
        }
        setShip(field, x, y);
        printFields(field);
        --counter;
    }
}

void fillingShipSome (char field[][sizeField], int numShip, int counter)
{
    while (counter) {
        std::cout << "ships left " << counter << std::endl;
        std::cout << "enter two coordinates (x1, y1, x2, y2)" << std::endl;
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1;
        std::cin >> x2 >> y2;
        if (!checkCorrectValue (x1, y1)) 
            continue;
        if (!checkCorrectValue (x2, y2)) 
            continue;
        if (x1 != x2 && y1 != y2 || std::abs(x1 - x2) + 1 != numShip && std::abs(y1 - y2) + 1 != numShip) {
            std::cout << "incorrect values. repeat" << std::endl;
            continue;
        }
        int normalX1, normalY1, normalX2, normalY2;
        normalX1 = (x1 > x2) ? x2 : x1;
        normalX2 = (x1 < x2) ? x2 : x1;
        normalY1 = (y1 > y2) ? y2 : y1;
        normalY2 = (y1 < y2) ? y2 : y1;
        if (checkShipSome(field, normalX1, normalY1, normalX2, normalY2)) {
            std::cout << "incorrect values. repeat" << std::endl;
            continue;
        }
        if (normalY1 == normalY2)
            for (int i = normalX1; i <= normalX2; ++i)
                setShip(field, i, normalY1);
        else if (normalX1 == normalX2)
            for (int i = normalY1; i <= normalY2; ++i)
                setShip(field, normalX1, i);
        printFields(field);
        --counter;
    }
}

void setShips(char matrix[][sizeField])
{
    int cntShipOne, cntShipTwo, cntShipThree, cntShipFour;
    cntShipOne = 4;
    cntShipTwo = 3;
    cntShipThree = 2;
    cntShipFour = 1;
    while (cntShipOne || cntShipTwo || cntShipThree || cntShipFour) {
        std::cout << "sets ships" << std::endl;
        std::cout << "1 - ShipOne" << std::endl << "2 - ShipTwo" << std::endl << "3 - ShipThree" << std::endl << "4 - ShipFour" << std::endl;
        int ship;
        std::cin >> ship;
        if (ship == 1 && cntShipOne) {
            fillingShipOne(matrix);
            cntShipOne = 0;
        } else if (ship == 2 && cntShipTwo) {
            fillingShipSome(matrix, 2, cntShipTwo);
            cntShipTwo = 0;
        } else if (ship == 3 && cntShipThree) {
            fillingShipSome(matrix, 3, cntShipThree);
            cntShipThree = 0;
        } else if (ship == 4 && cntShipFour) {
            fillingShipSome(matrix, 4, cntShipFour);
            cntShipFour = 0;
        }
    }
}

void initField (char field[][sizeField])
{
    for (int i = 0; i < sizeField; ++i)
        for (int j = 0; j < sizeField; ++j)
            field[i][j] = '_';
}

bool attack (char field[][sizeField], int x, int y)
{
    if (field[x][y] == 'O') {
        field[x][y] = 'X';
        std::cout << "You hint!";
        return true;
    } else {
        std::cout << "You past!";
        return false;
    }
}

int main ()
{
    char player1Attack[sizeField][sizeField], player1Ships[sizeField][sizeField], player2Attack[sizeField][sizeField], player2Ships[sizeField][sizeField];
    initField(player1Attack);
    initField(player1Ships);
    initField(player2Attack);
    initField(player2Ships);

    std::cout << "Player 1 place ships" << std::endl;
    setShips(player1Ships);
    std::cout << "Player 2 place ships" << std::endl;
    setShips(player2Ships);

    int cntAllShips1, cntAllShips2;
    cntAllShips1 = cntAllShips2 = 4 * 1 + 3 * 2 + 2 * 3 + 1 * 4;

    while (cntAllShips1 && cntAllShips2) {
        int x, y;
        bool isHint = true;

        while (isHint) {
            std::cout << "Player 1 ships" << std::endl;
            printFields(player1Ships);
            std::cout << "Player 1 to attack (x, y):" << std::endl;
            printFields(player1Attack);
            std::cin >> x >> y;
            if (attack(player1Attack, x, y))
                cntAllShips2--;
            else
                isHint = false;
            std::cout << "Player 1. You attacks:" << std::endl;
            printFields(player1Attack);
            std::cout << "Player 1. You ships:" << std::endl;
            printFields(player1Ships);
        }

        isHint = true;

        while (isHint) {
            std::cout << "Player 2 ships" << std::endl;
            setShips(player2Ships);
            std::cout << "Player 2 to attack (x, y):" << std::endl;
            setShips(player2Attack);
            std::cin >> x >> y;
            if (attack(player2Attack, x, y))
                cntAllShips1--;
            else
                isHint = false;
            std::cout << "Player 2. You attacks:" << std::endl;
            printFields(player2Attack);
            std::cout << "Player 2. You ships:" << std::endl;
            printFields(player2Ships);
        }
    }

    if (!cntAllShips2)
        std::cout << "Player 1 win" << std::endl;
    else if (!cntAllShips1)
        std::cout << "Player 2 win" << std::endl;

    return 0;
}
