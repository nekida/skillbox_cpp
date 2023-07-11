#include <iostream>
#include <string>
#include <cmath>
#include <vector>

enum RoomType {
    bedroom,
    kitchen,
    bathroom,
    children,
    living
};

enum BuildType {
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
    BuildType type;
    float s;
};

struct Region {
    unsigned ID;
    std::vector<House> houses;
    std::vector<OtherBuilding> otherBuilding;
};

int main ()
{
    std::vector<Region> village;

    std::cout << "Enter the number of regions:" << std::endl;
    int numRegions;
    std::cin >> numRegions;

    for (int i = 0; i < numRegions; ++i) {
        Region region;
        std::cout << "Enter the ID of region " << i + 1 << ":" << std::endl;
        std::cin >> region.ID;

        std::cout << "Enter the number of houses on region " << i + 1 << ":" << std::endl;
        int numHouses;
        std::cin >> numHouses;

        for (int j = 0; j < numHouses; ++j) {
            House house;
            std::cout << "Enter the area of house " << j + 1 << " (1..3):" << std::endl;
            std::cin >> house.s;
            std::cout << "Enter the number of levels on house " << j + 1 << " (1..3):" << std::endl;
            int numLevels;
            std::cin >> numLevels;

            for (int k = 0; k < numLevels; ++k) {
                Level level;
                std::cout << "Enter the ceiling height of level " << k + 1 << " (1..3):" << std::endl;
                std::cin >> level.h;
                std::cout << "Enter the number of rooms on level " << k + 1 << " (2..4):" << std::endl;
                int numRooms;
                std::cin >> numRooms;

                for (int l = 0; l < numRooms; ++l) {
                    Room room;
                    int numRoom = l + 1;
                    std::cout << "Enter the type of room " << numRoom << ":" << std::endl;
                    std::cout << "0 - bedroom, 1 - kitchen, 2 - bathroom, 3 - children, 4 - living" << std::endl;
                    int type;
                    std::cin >> type;
                    room.type = (RoomType)type;
                    std::cout << "Enter the area of room " << numRoom << ":" << std::endl;
                    std::cin >> room.s;

                    level.rooms.push_back(room);
                }
                house.levels.push_back(level);
            }
            region.houses.push_back(house);
        }

        std::cout << "Enter the number of other buildings on region " << i + 1 << ":" << std::endl;
        int numOtherBuild;
        std::cin >> numOtherBuild;

        for (int j = 0; j < numOtherBuild; ++j) {
            OtherBuilding otherBuilding;
            std::cout << "Enter the area of other building " << j + 1 << std::endl;
            std::cin >> otherBuilding.s;
            std::cout << "Enter the type of other building " << j + 1 << " (1..3):" << std::endl;
            std::cout << "0 - garage, 1 - shed, 2 - sauna" << std::endl;
            int type;
            std::cin >> type;
            otherBuilding.type = (BuildType)type;
            region.otherBuilding.push_back(otherBuilding);
        }

        village.push_back(region);
    }

    return 0;
}
