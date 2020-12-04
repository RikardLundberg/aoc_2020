#include <iostream>
#include <vector>
#include <string>

int main()
{
	//int currentPassport = 0;
	std::string input;
	//std::vector<std::vector<std::string>> passport;
	int validCount = 0;

	int determinationCount = 0;

	while(std::getline(std::cin, input) && input != "eof"){
		if (input == "")
		{
			//currentPassport++;
			if (determinationCount == 7)
				validCount++;

			determinationCount = 0;
			continue;
		}
		auto tmpStr = input + " ";
		while (tmpStr != "")
		{
			auto checkStr = tmpStr.substr(0, tmpStr.find(" ")).substr(0,tmpStr.find(":"));
			if (checkStr == "byr" || checkStr == "iyr" || checkStr == "eyr" || checkStr == "hgt" || checkStr == "hcl" || checkStr == "ecl" || checkStr == "pid")
				determinationCount++;
			tmpStr = tmpStr.substr(tmpStr.find(" ") + 1);
		}
		//passport[currentPassport].push_back(currentPassport);
	}


	std::cout << validCount << std::endl;
}
