#include <iostream>
#include <cassert>

float travelTime (float distance, float speed)
{
    assert (speed < 0.0);
    return distance * speed;
}

int main ()
{
    std::cout << travelTime (1.0, 10.0) << std::endl;
    std::cout << travelTime (1.0, -10.0) << std::endl;
    std::cout << travelTime (2.0, 20.0) << std::endl;

    return 0;
}
