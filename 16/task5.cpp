#include <iostream>
#include <string>
#include <sstream>

bool isTurnWaterHeatingSystem (double temp)
{
	if (temp < 0.0)
		return true;
	else if (temp > 5.0)
		return false;
}

bool isTurnGardenLighting (int time, bool isMove)
{
	return (time > 16 || time < 5) && isMove;
}

int main ()
{

   return 0;
}
