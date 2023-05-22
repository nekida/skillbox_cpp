#include <iostream>
#include <string>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};

static int switchesState = 0;

bool isTurnGardenLighting (int time)
{
	return (time > 16 || time < 5);
}

bool isTempOfLight (int time)
{
	return (time > 16 && time <= 20);
}

void printState ()
{
    static int prevState = 0;
    if ((switchesState ^ prevState) & LIGHTS_INSIDE) {
        (switchesState & LIGHTS_INSIDE) ? std::cout << "Lights inside is ON" : std::cout << "Lights inside is OFF";
        std::cout << std::endl;
    }
    if ((switchesState ^ prevState) & LIGHTS_OUTSIDE) {
        (switchesState & LIGHTS_OUTSIDE) ? std::cout << "Lights outside is ON" : std::cout << "Lights outside is OFF";
        std::cout << std::endl;
    }
    if ((switchesState ^ prevState) & HEATERS) {
        (switchesState & HEATERS) ? std::cout << "Heaters is ON" : std::cout << "Heaters is OFF";
        std::cout << std::endl;
    }
    if ((switchesState ^ prevState) & WATER_PIPE_HEATING) {
        (switchesState & WATER_PIPE_HEATING) ? std::cout << "Water pipe heating is ON" : std::cout << "Water pipe heating is OFF";
        std::cout << std::endl;
    }
    if ((switchesState ^ prevState) & CONDITIONER) {
        (switchesState & CONDITIONER) ? std::cout << "Conditioner is ON" : std::cout << "Conditioner is OFF";
        std::cout << std::endl;
    }
    prevState = switchesState;
}

void setState (switches state)
{
    switchesState |= state;
}

void resetState (switches state)
{
    switchesState &= ~state;
}

int main ()
{
     int time = 0;
     int tempOfLight = 5000;
     int deltaTempOfLight = (5000 - 2700) / 4;
     while (time <= 24) {
        std::cout << "Time: " << time << ":00. Input states of sensors and light: " << std::endl;
        std::string buffer, strMove, strLight;
        getline(std::cin, buffer);
        std::stringstream temp_stream(buffer);

        double tempOutside, tempInside;
        bool isMove, isTurnLighting;

        temp_stream >> tempOutside >> tempInside >> strMove >> strLight;

        isMove = (strMove == "yes") ? true : false;
        isTurnLighting = (strLight == "on") ? true : false;

        if (tempOutside < 0.0)
		    setState (WATER_PIPE_HEATING);
	    else if (tempOutside > 5.0)
		    resetState (WATER_PIPE_HEATING);

        if (isTurnGardenLighting (time) && isMove)
            setState (LIGHTS_OUTSIDE);
        else
            resetState (LIGHTS_OUTSIDE);

        if (tempInside < 22.0)
            setState (HEATERS);
        else if (tempInside >= 25.0)
            resetState (HEATERS);

        if (tempInside >= 30.0)
            setState (CONDITIONER);
        else if (tempInside <= 25.0)
            resetState (CONDITIONER);

        if (isTempOfLight (time) && isTurnLighting) {
            tempOfLight -= deltaTempOfLight;
            std::cout << "color temperature is " << tempOfLight << std::endl;
        }

        printState ();

        ++time;
        if (time == 24) {
            time = 0;
            tempOfLight = 5000;
        }
     }

    return 0;
}
