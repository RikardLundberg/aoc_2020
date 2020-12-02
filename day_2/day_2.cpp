#include <iostream>
#include <string>

int main()
{
	std::string input;

	auto validPasswords = 0;
	while (std::cin >> input)
	{
		if (input.compare("eof") == 0)
			break;
		auto firstPos = std::stoi(input.substr(0, input.find("-")));
		auto secondPos = std::stoi(input.substr(input.find("-") + 1, input.find(" ")));
		std::cin >> input;
		char policy = input.substr(0, input.find(":"))[0];
		std::cin >> input;
		auto password = input.substr(0, input.length());

		auto posCounter = 1;
		auto foundMatches = 0;
		for (char ch : password) {
			if (ch == policy && (secondPos == posCounter || firstPos == posCounter)) 
				foundMatches++;
			posCounter++;
		}

		if (foundMatches == 1)
			validPasswords++;
	}

	std::cout << validPasswords << std::endl;
}
