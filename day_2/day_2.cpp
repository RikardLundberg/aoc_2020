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
		auto lowerBound = std::stoi(input.substr(0, input.find("-")));
		auto higherBound = std::stoi(input.substr(input.find("-") + 1, input.find(" ")));
		std::cin >> input;
		char policy = input.substr(0, input.find(":"))[0];
		std::cin >> input;
		auto password = input.substr(0, input.length());

		auto count = 0;
		for(char ch : password) 
			if (ch == policy)
				count++;
		if (count <= higherBound && count >= lowerBound)
			validPasswords++;
	}

	std::cout << validPasswords << std::endl;
}
