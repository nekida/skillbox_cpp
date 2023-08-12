#include <iostream>
#include <string>
#include <math.h>

enum class Color {
    None = 0,
    Red,
    Blue,
    Green,
    Pink,
    Max
};

struct Coordinates {
    double centreX;
    double centreY;
};

class Figure {
    std::string name = "";

    Coordinates coordinates;

    Color color;

    std::string Colors[static_cast<unsigned>(Color::Max)] = {
        "None", "Red", "Blue", "Green", "Pink"
    };

public:
    Figure(std::string& inName, Coordinates& inCoordinates, Color inColor)
        : name(inName), coordinates(inCoordinates), color(inColor) {}

    std::string getName() const { return name; }

    Coordinates getCoordinates() const { return coordinates; }

    std::string getColor() const { return Colors[static_cast<unsigned>(color)]; }

    void printRectangle()
    {
        double maxY = coordinates.centreY * 2;
        double maxX = coordinates.centreX * 2;
        for (int i = 0; i < maxY; ++i) {
            for (int j = 0; j < maxX; ++j) {
                if (i == 0 || i == maxY - 1)
                    std::cout << '-';
                else if (j == 0 || j == maxX - 1)
                    std::cout << '|';
                else
                    std::cout << ' ';
            }
            std::cout << std::endl;
        }
    }
};

class Circle : public Figure {
public:
    Circle(std::string& inName, Coordinates& inCoordinates, Color inColor)
        : Figure(inName, inCoordinates, inColor) {}

    double calcArea()
    {
        return fabs(getCoordinates().centreX) * 4 * atan(1);
    }
};

class Triangle : public Figure {
public:
    Triangle(std::string& inName, Coordinates& inCoordinates, Color inColor)
        : Figure(inName, inCoordinates, inColor) {}

    double calcArea()
    {
        return (getCoordinates().centreX * 4 * std::sqrt(3)) / 4;
    }
};

class Square : public Figure {
public:
    Square(std::string& inName, Coordinates& inCoordinates, Color inColor)
        : Figure(inName, inCoordinates, inColor) {}

    double calcArea()
    {
        return getCoordinates().centreX * 4;
    }
};

class Rectangle : public Figure {
public:
    Rectangle(std::string& inName, Coordinates& inCoordinates, Color inColor)
        : Figure(inName, inCoordinates, inColor) {}

    double calcArea()
    {
        return getCoordinates().centreX * 2 * getCoordinates().centreY * 2;
    }
};

int main ()
{
    std::cout << "Enter name of the figure (circle, square, triangle, rectangle):" << std::endl;
    std::string cmd;
    std::cin >> cmd;
    if (cmd == "circle") {
        Coordinates coor = { 4, 4 };
        Circle circle(cmd, coor, Color::Red);
        std::cout << "Name: " << circle.getName() << std::endl;
        std::cout << "Color: " << circle.getColor() << std::endl;
        std::cout << "Area: " << circle.calcArea() << std::endl;
        circle.printRectangle();
        std::cout << std::endl;
    } else if (cmd == "triangle") {
        Coordinates coor = { 4, 2 };
        Triangle triangle(cmd, coor, Color::Blue);
        std::cout << "Name: " << triangle.getName() << std::endl;
        std::cout << "Color: " << triangle.getColor() << std::endl;
        std::cout << "Area: " << triangle.calcArea() << std::endl;
        triangle.printRectangle();
        std::cout << std::endl;
    } else if (cmd == "square") {
        Coordinates coor = { 4, 4 };
        Square square(cmd, coor, Color::Green);
        std::cout << "Name: " << square.getName() << std::endl;
        std::cout << "Color: " << square.getColor() << std::endl;
        std::cout << "Area: " << square.calcArea() << std::endl;
        square.printRectangle();
        std::cout << std::endl;
    } else if (cmd == "rectangle") {
        Coordinates coor = { 4, 8 };
        Rectangle rectangle(cmd, coor, Color::Green);
        std::cout << "Name: " << rectangle.getName() << std::endl;
        std::cout << "Color: " << rectangle.getColor() << std::endl;
        std::cout << "Area: " << rectangle.calcArea() << std::endl;
        rectangle.printRectangle();
        std::cout << std::endl;
    } else
        std::cout << "Unsupported command" << std::endl;

    return 0;
}
