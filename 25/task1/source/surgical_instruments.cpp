#include <iostream>

#include "surgical_instruments.h"

void scalpel (Coordinates start, Coordinates end)
{
    std::cout << "The cut between " << start.x << ", " << start.y << " and " << end.x << ", " << end.y << "." << std::endl;
}

void hemostat (Coordinates place)
{
    std::cout << "Clamp in place " << place.x << ", " << place.y << "." << std::endl;
}

void tweezers (Coordinates place)
{
    std::cout << "Tweezers are in place " << place.x << ", " << place.y << "." << std::endl;
}

void suture (Coordinates start, Coordinates end)
{
    std::cout << "The seam between " << start.x << ", " << start.y << " and " << end.x << ", " << end.y << "." << std::endl;
}
