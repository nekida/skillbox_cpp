#include <iostream>
#include <vector>
#include <string>

class Coordinate {
    float x;
    float y;

public:
    Coordinate(float coordX, float coordY) :
        x(coordX), y(coordY) {}

    const float getX() const {
        return x;
    }

    const float getY() const {
        return y;
    }
};

class Locations {
    std::vector<Coordinate> coordinates;

public:
    Locations(std::initializer_list<Coordinate> _coordinates) :
        coordinates(_coordinates) {}

    const std::vector<Coordinate>& getCoordinates() const {
        return coordinates;
    }
};

int main ()
{
    Locations locations = Locations{ {1.1, 2.2}, {3.3, 4.4}, {5.5, 6.6}, {7.7, 8.8}, {9.9, 0.9} };

    for (const auto& position : locations.getCoordinates()) {
        static size_t numPos = 1;
        std::cout << "Position " << numPos++ << ", coordinates: x = " << position.getX() << ", y = " << position.getY() << std::endl;
    }

    return 0;
}
