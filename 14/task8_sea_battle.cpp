#include <iostream>

static constexpr int sizeField = 10;

void printFields (bool matrix[][sizeField])
{
    std::cout << "   ";
    for (int i = 0; i < sizeField; ++i)
        std::cout << i << ' ';
    std::cout << std::endl;
    for (int i = 0; i < sizeField; ++i) {
        std::cout << i << "  ";
        for (int j = 0; j < sizeField; ++j) {
            matrix[i][j] ? std::cout << "O " : std::cout << "_ ";
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

bool setShip (bool field[][sizeField], int x, int y)
{
    if (!field[x][y]) {
        field[x][y] = true;
        return true;
    }
    std::cout << "incorrect values. repeat" << std::endl;
    return false;
}

void fillingShipOne (bool field[][sizeField])
{
    int counter = 4;
    while (counter) {
        std::cout << "input " << 1 <<  " coordinate" << std::endl;
        int x, y;
        std::cin >> x >> y;
        if (!checkCorrectValue (x, y)) 
            continue;
        if (!setShip(field, x, y))
            continue;
        --counter;
    }
}

void fillingShipSome (bool field[][sizeField], int numShip, int counter)
{
    while (counter) {
        std::cout << "input " << numShip <<  " coordinate" << std::endl;
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
        if (y1 == y2)
            for (int i = x1; i <= x2; ++i)
                if (!setShip(field, i, y1))
                    continue;
        else if (x1 == x2)
            for (int i = y1; i <= y2; ++i)
                if (!setShip(field, x1, i))
                    continue;
        --counter;
    }
}

void setShips(bool matrix[][sizeField])
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
        if (ship == 1) {
            fillingShipOne(matrix);
            printFields(matrix);
            cntShipOne = 0;
        } else if (ship == 2) {
            fillingShipSome(matrix, 2, cntShipTwo);
            printFields(matrix);
            cntShipTwo = 0;
        } else if (ship == 3) {
            fillingShipSome(matrix, 3, cntShipThree);
            cntShipThree = 0;
        } else if (ship == 4) {
            fillingShipSome(matrix, 4, cntShipFour);
            cntShipFour = 0;
        }
    }
}

void initField (bool field[][sizeField])
{
    for (int i = 0; i < sizeField; ++i)
        for (int j = 0; j < sizeField; ++j)
            field[i][j] = false;
}

int main ()
{
    bool player1Field[sizeField][sizeField], player1Ships[sizeField][sizeField], player2Field[sizeField][sizeField], player2Ships[sizeField][sizeField];
    initField(player1Ships);
    setShips(player1Ships);
    printFields(player1Ships);

    return 0;
}

