#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string n;
	std::vector<std::string> inputs;

	while (std::cin >> n && n != "eof")
		inputs.push_back(n);

	int treeCounter = 0;
	int currentXPos = 0;
	for (auto str : inputs) 
	{
		auto strPos = (str.length() + currentXPos) % str.length();
		if (str[strPos] == '#')
			treeCounter++;

		currentXPos += 3;
	}

	std::cout << treeCounter << std::endl;
}
