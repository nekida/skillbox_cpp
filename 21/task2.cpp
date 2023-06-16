#include <iostream>
#include <string>
#include <cmath>
#include <vector>

enum RoomType
{
    bedroom,
    kitchen,
    bathroom,
    children,
    living
};

enum BuildType
{
    garage,
    shed,
    sauna
};

struct Room {
    RoomType type;
    float s;
};

struct Level {
    float h;
    std::vector<Room> rooms;
};

struct House {
    float s;
    std::vector<Level> levels;
};

struct OtherBuilding {
    RoomType type;
    float s;
};

struct region {
    unsigned ID;
    std::vector<House> houses;
    std::vector<OtherBuilding> otherBuilding;
};

int main ()
{
    std::cout << "Enter the number of regions:" << std::endl;
    int numRegions;
    std::cin >> numRegions;

    std::vector<region> village(numRegions);
    for (int i = 0; i < numRegions; ++i) {
        std::cout << "Enter the ID of region " << i + 1 << ":" << std::endl;
        std::cin >> village[i].ID;
        std::cout << "Enter the number of houses on region " << i + 1 << ":" << std::endl;
        int numHouses;
        std::cin >> numHouses;
        village[i].houses.resize (numHouses);
        for (int j = 0; j < numHouses; ++j) {
            std::cout << "Enter the number of levels on house " << j + 1 << " (1-3):" << std::endl;
            int numLevels;
            std::cin >> numLevels;
            village[i].houses[j].levels.resize (numLevels);
            for (int k = 0; k < numLevels; ++k) {
                std::cout << "Enter the number of rooms on level " << k + 1 << ":" << std::endl;
                int numRooms;
                std::cin >> numRooms;
                village[i].houses[j].levels[k].rooms.resize (numRooms);
                for (int l = 0; l < numLevels; ++l) {
                    int numRoom = l + 1;
                    std::cout << "Enter the type of room " << numRoom << ":" << std::endl;
                    std::cout << "0 - bedroom, 1 - kitchen, 2 - bathroom, 3 - children, 4 - living" << std::endl;
                    int type;
                    std::cin >> type;
                    village[i].houses[j].levels[k].rooms[l].type = (RoomType)type;

                    std::cout << "Enter the area of room " << numRoom << ":" << std::endl;
                    std::cin >> village[i].houses[j].levels[k].rooms[l].s;
                }
            }
        }
    }

    return 0;
}
