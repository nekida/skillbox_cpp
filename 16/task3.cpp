#include <iostream>
#include <string>
#include <sstream>

int main ()
{
	std::cout << "Input first value, operation and second value: " << std::endl;
	std::string buffer;
	std::cin >> buffer;
	std::stringstream temp_stream(buffer);

	char op;
	double first, second;
	temp_stream >> first >> op >> second;

	if (op == '+')
		std::cout << first + second;
	else if (op == '-')
		std::cout << first - second;
	else if (op == '/') {
		if (second == 0.0)
			std::cout << "Div on zero" << std::endl;
		std::cout << first / second;
	} else if (op == '*')
		std::cout << first * second;

   return 0;
}
