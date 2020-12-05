#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int TranslateBinary(std::string val);
int main()
{
	std::vector<int> IDs;
	std::string input;
	while (std::cin >> input && input != "eof")
	{
		auto colPos = input.find('R') < input.find('L') ? input.find('R') : input.find('L');
		auto colStr = input.substr(colPos);
		auto rowStr = input.substr(0, colPos);
		auto col = TranslateBinary(colStr);
		auto row = TranslateBinary(rowStr);
		IDs.push_back(row * 8 + col);
	}

	std::sort(IDs.begin(), IDs.end());

	int currentSeat = IDs[0]-1;
	int mySeat = 0;
	for (int ID : IDs) {
		if (ID != ++currentSeat) 
		{
			mySeat = currentSeat;
			break;
		}
	}

	std::cout << mySeat << std::endl;
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