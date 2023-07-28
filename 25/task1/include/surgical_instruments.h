#pragma once

struct Coordinates {
    double x;
    double y;
};

void scalpel (Coordinates start, Coordinates end);
void hemostat (Coordinates place);
void tweezers (Coordinates place);
void suture (Coordinates start, Coordinates end);
