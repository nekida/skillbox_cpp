#include <iostream>
#include <string>

std::string one, two, three;

char getElement (int x, int y)
{
	if (x < 1 || x > 3 || y < 1 || y > 3 || one.length () == 0 || two.length () == 0 || three.length () == 0)
		return '\0';
	if (x == 1)
		return one[y - 1];
	else if (x == 2)
		return two[y - 1];
	else
		return three[y - 1];
}

bool checkCorrectSymbols ()
{
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			char ch = getElement (i, j);
			if (ch != '.' && ch != 'X' && ch != 'O')
				return false;
		}
	}
	return true;
}

std::string getColumn (int num)
{
	if (num < 1 || num > 3)
		return "";
	std::string str;
	for (int i = 1; i <= 3; i++) {
		char ch = getElement (i, num);
		if (ch == '\0')
			return "";
		else
			str.push_back (ch);
	}
	return str;
}

std::string getRow (int num)
{
	if (num < 1 || num > 3)
		return "";
	std::string str;
	for (int i = 1; i <= 3; i++) {
		char ch = getElement (num, i);
		if (ch == '\0')
			return "";
		else
			str.push_back (ch);
	}
	return str;
}

std::string getStraightDiag ()
{
	std::string str;
	for (int i = 1, j = 1; i <= 3; i++, j++) {
		char ch = getElement (i, j);
		if (ch == '\0')
			return "";
		else
			str.push_back (ch);
	}
	return str;
}

std::string getReverseDiag ()
{
	std::string str;
	for (int i = 1, j = 3; i <= 3; i++, j--) {
		char ch = getElement (i, j);
		if (ch == '\0')
			return "";
		else
			str.push_back (ch);
	}
	return str;
}

int getChInStr (std::string str, char ch)
{
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		if (str[i] == ch)
			cnt++;
	return cnt;
}
 
int getAllCharsInStrs (char ch)
{
	int cnt = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (ch == getElement(i, j))
				cnt++;
		}
	}
	return cnt;
}

bool checkCorrectNumSymbols ()
{
	return (getAllCharsInStrs('O') > getAllCharsInStrs('X')) ? false : true;
}

char getChWinner (std::string str)
{
	int cntX, cntO;
	cntX = getChInStr (str, 'X');
	cntO = getChInStr (str, 'O');
	if (cntX == 3)
		return 'X';
	else if (cntO == 3)
		return 'O';
	else
		return '.';
}

int getWinner (char ch)
{
	int cnt = 0;
	if (getChWinner (getRow (1)) == ch)
		cnt++;
	if (getChWinner (getRow (2)) == ch)
		cnt++;
	if (getChWinner (getRow (3)) == ch)
		cnt++;
	if (getChWinner (getColumn (1)) == ch)
		cnt++;
	if (getChWinner (getColumn (2)) == ch)
		cnt++;
	if (getChWinner (getColumn (3)) == ch)
		cnt++;
	if (getChWinner (getStraightDiag ()) == ch)
		cnt++;
	if (getChWinner (getReverseDiag ()) == ch)
		cnt++;
	return cnt;
}

int main ()
{
	std::cout << "Input three strings for field:" << std::endl;
	std::cin >> one >> two >> three;

	if (one.length() != 3 || two.length() != 3 || three.length() != 3) {
		std::cout << "Input error" << std::endl;
		return 0;
	}

	if (!checkCorrectSymbols() || !checkCorrectNumSymbols()) {
		std::cout << "Incorrect" << std::endl;
		return 0;
	}

	if (getAllCharsInStrs('X') == 2 && getAllCharsInStrs('O') == 2) {
		std::cout << "Nobody" << std::endl;
		return 0;
	}

	int PetyaWon = getWinner('X');
	int VanyaWon = getWinner('O');

	if (PetyaWon > 0 && VanyaWon > 0)
		std::cout << "Incorrect" << std::endl;
	else if ((PetyaWon > 0 && getAllCharsInStrs('O') >= 3) || (VanyaWon > 0 && getAllCharsInStrs('X') > 3))
		std::cout << "Incorrect" << std::endl;
	else if (PetyaWon > 0)
		std::cout << "Petya won" << std::endl;
	else if (VanyaWon > 0)
		std::cout << "Vanya won" << std::endl;
	else
		std::cout << "Nobody" << std::endl;
}
