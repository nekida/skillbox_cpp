#include <iostream>
#include <string>

static constexpr int sizeField = 12;

void printMatrix (bool matrix[][sizeField])
{
    for (int i = 0; i < sizeField; ++i) {
        for (int j = 0; j < sizeField; ++j)
            matrix[i][j] ? std::cout << "o " : std::cout << "x ";
        std::cout << std::endl;
    }
}

void initMatrix (bool matrix[][sizeField])
{
    for (int i = 0; i < sizeField; ++i)
        for (int j = 0; j < sizeField; ++j)
            matrix[i][j] = true;
}

bool toPop (bool matrix[][sizeField], int x1, int y1, int x2, int y2)
{
    if (x1 < 1 || x1 > sizeField || y1 < 1 || y1 > sizeField ||
            x2 < 1 || x2 > sizeField || y2 < 1 || y2 > sizeField)
        return false;
    for (int i = x1 - 1; i <= x2 - 1; ++i) {
        for (int j = y1 - 1; j <= y2 - 1; ++j) {
            if (matrix[i][j]) {
                std::cout << "Pop!" << std::endl;
                matrix[i][j] = false;
            }
        }
    }
    return true;
}

bool checkMatrix (bool matrix[][sizeField])
{
    for (int i = 0; i < sizeField; ++i)
        for (int j = 0; j < sizeField; ++j)
            if (matrix[i][j])
                return true;
    return false;
}

int main ()
{
    bool field[sizeField][sizeField];
    initMatrix (field);

    std::cout << "Pupyrka state:" << std::endl;
    printMatrix (field);

    while (checkMatrix (field)) {
        int startX, startY, endX, endY;
        std::cout << "Enter region coordinates:" << std::endl;
        std::cout << "Start region (x, y) (1..12): ";
        std::cin >> startX >> startY;
        std::cout << "End region (x, y) (1..12): ";
        std::cin >> endX >> endY;
        if (!toPop (field, startX, startY, endX, endY)) {
            std::cout << "Incorrect values. Ending." << std::endl;
            return 0;
        }
        std::cout << "Pupyrka state:" << std::endl;
        printMatrix (field);
    }
    std::cout << "No bubbles left" << std::endl;

    return 0;
}
