#include <iostream>
#include <vector>
#include <string>
#include <regex>

int controlString(std::string checkStr, std::string val);
int main()
{
	std::string input;
	int validCount = 0;
	int determinationCount = 0;

	while(std::getline(std::cin, input) && input != "eof"){
		if (input == "")
		{
			if (determinationCount == 7)
				validCount++;

			determinationCount = 0;
			continue;
		}
		auto tmpStr = input + " ";
		while (tmpStr != "")
		{
			auto checkStr = tmpStr.substr(0, tmpStr.find(" "));
			auto key = checkStr.substr(0, tmpStr.find(":"));
			auto val = checkStr.substr(tmpStr.find(":")+1);
			if (controlString(key, val))
				determinationCount++;
			tmpStr = tmpStr.substr(tmpStr.find(" ") + 1);
		}
	}

	std::cout << validCount << std::endl;
}


int controlString(std::string checkStr, std::string value)
{
	if (checkStr == "byr") 
	{
		auto val = std::stoi(value);
		if (val >= 1920 && val <= 2002)
			return 1;
	} 
	else if (checkStr == "iyr")
	{
		auto val = std::stoi(value);
		if (val >= 2010 && val <= 2020)
			return 1;
	}
	else if (checkStr == "eyr")
	{
		auto val = std::stoi(value);
		if (val >= 2020 && val <= 2030)
			return 1;
	}
	else if (checkStr == "hgt")
	{
		if (value.length() < 3)
			return 0;
		auto key = value.substr(value.length() - 2);
		auto val = std::stoi(value.substr(0, value.length() - 2));
		if (key == "in" && val >= 59 && val <= 76)
			return 1;
		if (key == "cm" && val >= 150 && val <= 196)
			return 1;
	}
	else if (checkStr == "hcl")
	{
		if (std::regex_match(value, std::regex("#[0-9a-f]{6}$")))
			return 1;
	}
	else if (checkStr == "ecl")
	{
		if (value == "amb" || value == "blu" || value == "brn" || value == "gry" || value == "grn" || value == "hzl" || value == "oth")
			return 1;
	}
	else if (checkStr == "pid")
	{
		if (std::regex_match(value, std::regex("[0-9]{9}$")))
			return 1;
	}
	return 0;
}