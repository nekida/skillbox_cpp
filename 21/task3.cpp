#include <iostream>
#include <string>
#include <cmath>

struct vector {
    float x;
    float y;
};

void cmdAdd ()
{
    vector v1, v2;
    std::cout << "Enter the coordinates of the first vector (x/y):" << std::endl;
    std::cin >> v1.x >> v1.y;
    std::cout << "Enter the coordinates of the second vector (x/y):" << std::endl;
    std::cin >> v2.x >> v2.y;
    std::cout << "Result: x = " << v1.x + v2.x << ", y = " << v1.y + v2.y << std::endl;
}

void cmdSubtract ()
{
    vector v1, v2;
    std::cout << "Enter the coordinates of the first vector (x/y):" << std::endl;
    std::cin >> v1.x >> v1.y;
    std::cout << "Enter the coordinates of the second vector (x/y):" << std::endl;
    std::cin >> v2.x >> v2.y;
    std::cout << "Result: x = " << v1.x - v2.x << ", y = " << v1.y - v2.y << std::endl;
}

void cmdScale ()
{
    vector v;
    int scalar;
    std::cout << "Enter the coordinates of vector (x/y):" << std::endl;
    std::cin >> v.x >> v.y;
    std::cout << "Enter the scalar:" << std::endl;
    std::cin >> scalar;
    std::cout << "Result: x = " << v.x * scalar << ", y = " << v.y * scalar << std::endl;
}

void cmdLength ()
{
    vector v;
    std::cout << "Enter the coordinates of vector (x/y):" << std::endl;
    std::cin >> v.x >> v.y;
    std::cout << "Result: x = " << sqrt ((v.x * v.x) + (v.y * v.y)) << std::endl;
}

void cmdNormalize ()
{
    vector v;
    std::cout << "Enter the coordinates of vector (x/y):" << std::endl;
    std::cin >> v.x >> v.y;
    float inversLen = 1.0F / sqrt ((v.x * v.x) + (v.y * v.y));
    std::cout << "Result: x = " << v.x * inversLen << ", y = " << v.y * inversLen << std::endl;
}

int main ()
{
    std::cout << "Enter the command (add/subtract/scale/length/normalize):" << std::endl;
    std::string command;
    std::cin >> command;

    if (command == "add") {
        cmdAdd ();
    } else if (command == "subtract") {
        cmdSubtract ();
    } else if (command == "scale") {
        cmdScale ();
    } else if (command == "length") {
        cmdLength ();
    } else if (command == "normalize") {
        cmdNormalize ();
    } else
        std::cout << "Unsupported command" << std::endl;

    return 0;
}
