#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct BoundingBoxDimensions {
    double width;
    double height;
};

class Shape {
public:
    virtual double square() = 0;

    virtual BoundingBoxDimensions dimensions() = 0;

    virtual std::string type() = 0;
};

void printParams(Shape* shape) {
    std::cout << "Type: " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    std::cout << "Width: " << shape->dimensions().width << std::endl;
    std::cout << "Height: " << shape->dimensions().height << std::endl;
}

class Circle : public Shape {
    double radius;

public:
    Circle(double _radius) : radius(_radius) {}

    double square() override { return 3.14 * radius * radius; }

    BoundingBoxDimensions dimensions() override { return { radius * 2, radius * 2 }; }

    std::string type() override { return "Circle"; }
};

class Rectangle : public Shape {
    double a;

    double b;

public:
    Rectangle(double _a, double _b) : a(_a), b(_b) {}

    double square() override { return a * b; }

    BoundingBoxDimensions dimensions() override { return { a, b }; }

    std::string type() override { return "Rectangle"; }
};

class Triangle : public Shape {
    double a;

    double b;

    double c;

public:
    Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    double square() override {
        double halfPerim = (a + b + c) / 2;
        return std::sqrt(halfPerim * (halfPerim - a) * (halfPerim - b) * (halfPerim - c));
    }

    BoundingBoxDimensions dimensions() override {
        double d = 2 * (a * b * c) / (4 * square());
        return { d, d }; 
    }

    std::string type() override { return "Triangle"; }
};

int main ()
{
    Circle c(5);
    printParams(&c);

    std::cout << std::endl;

    Rectangle r(5, 7);
    printParams(&r);

    std::cout << std::endl;

    Triangle t(3, 4, 5);
    printParams(&t);

    return 0;
}
