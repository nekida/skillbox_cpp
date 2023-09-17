#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

int main ()
{
    nlohmann::json infoFilm = {
        {"title", "Godzilla"},
        {"year", 2014},
        {"country", "USA, Japan"},
        {"production company", "Warner Bros."},
        {"writings", "Ishiro Honda, Takeo Murata"},
        {"produced", "Yoshimitsu Banno"},
        {"directed", "Gareth Edwards"},
        {"cast",
            {"Aaron Taylor-Johnson", "Ford Brody"},
            {"Ken Watanabe", "Dr. Ishiro Serizawa"},
            {"Bryan Cranston", "Joe Brody"},
            {"Elizabeth Olsen", "Elle Brody"}
        }
    };

    std::ofstream filmInfo("filmInfo.json");
    filmInfo << infoFilm;

    return 0;   
}
