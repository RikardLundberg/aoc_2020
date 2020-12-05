#include <iostream>
#include <string>

int TranslateBinary(std::string val);
int main()
{
	int highestId = 0;
	std::string input;
	while (std::cin >> input && input != "eof")
	{
		auto colPos = input.find('R') < input.find('L') ? input.find('R') : input.find('L');
		auto colStr = input.substr(colPos);
		auto rowStr = input.substr(0, colPos);
		auto col = TranslateBinary(colStr);
		auto row = TranslateBinary(rowStr);
		auto ID = row * 8 + col;
		if (ID > highestId)
			highestId = ID;
	}

	std::cout << highestId << std::endl;
}

int TranslateBinary(std::string val)
{
	int retVal = 0;
	int positionWorth = 1;
	while(val.length() > 0)
	{
		auto transChar = val.substr(val.length() - 1);
		val = val.substr(0, val.length() - 1);
		if (transChar == "B" || transChar == "R")
			retVal += positionWorth;
		positionWorth *= 2;
	}
	return retVal;
}