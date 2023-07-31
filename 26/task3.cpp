#include <iostream>
#include <string>
#include <vector>

class Window {
public:
    struct Coordinate {
        int x;
        int y;
    };

    void move(Coordinate& coor);

    void resize(int w, int h);

    void display();

    void close();

    static constexpr int maxWidth = 80;

    static constexpr int maxHeight = 50;

private:
    Coordinate coordinate;

    int width = 0;

    int height = 0;
};

void Window::move(Coordinate& coor)
{
    if (coor.x < 0 || coor.y < 0 || coor.x > maxWidth || coor.y > maxHeight)
        return;
    coordinate.x = coor.x;
    coordinate.y = coor.y;
    std::cout << "New coordinates - x: " << coordinate.x << ", " << "y: " << coordinate.y << std::endl;
}

void Window::resize(int w, int h)
{
    if (w < 0 || h < 0)
        return;
    width = w;
    height = h;
}

void Window::display()
{
    for (int i = 0; i < maxWidth; ++i) {
        for (int j = 0; j < maxHeight; ++j) {
            if ((i >= coordinate.x && i <= coordinate.x + width) &&
                    (j >= coordinate.y && j <= coordinate.y + height))
                std::cout << '1';
            else
                std::cout << '0';
        }
        std::cout << std::endl;
    }
}

void Window::close()
{
    coordinate.x = 0;
    coordinate.y = 0;
    width = 0;
    height = 0;
}

int main ()
{
    Window window;
    std::cout << "Enter the command" << std::endl;
    std::string cmd;
    std::cin >> cmd;

    while (cmd != "close") {
        if (cmd == "move") {
            std::cout << "Enter new coordinates (x, y)" << std::endl;
            Window::Coordinate coor;
            std::cin >> coor.x >> coor.y;
            window.move(coor);
        } else if (cmd == "resize") {
            std::cout << "Enter new width and height" << std::endl;
            int w, h;
            std::cin >> w >> h;
            window.resize(w, h);
        } else if (cmd == "display")
            window.display();
        else if (cmd == "close")
            window.close();
        else
            std::cout << "Unsupported command" << std::endl;

        std::cout << "Enter the command" << std::endl;
        std::cin >> cmd;
    }

    return 0;
}
