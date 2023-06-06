#include <iostream>
#include <fstream>
#include <ctime>

int main ()
{
    std::srand(std::time(nullptr));
    std::cout << "Enter height and width" << std::endl;
    int height, width;
    std::cin >> height >> width;

    int arr[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            arr[i][j] = std::rand() % 2;
        }
    }

    std::ofstream file ("pic.txt");
    if (!file.is_open()) {
        std::cout << "Error open file" << std::endl;
        return 0;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            file << arr[i][j];
        }
        file << std::endl;
    }

    file.close();

    return 0;
}
