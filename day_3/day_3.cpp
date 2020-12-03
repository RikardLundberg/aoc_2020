#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::string n;
	std::vector<std::string> inputs;

	while (std::cin >> n && n != "eof")
		inputs.push_back(n);

	int treeCounter[] = {0,0,0,0,0};
	int currentXPos[] = {0,0,0,0,0};
	bool skipSlope5 = false;
	for (auto str : inputs) 
	{
		for (int slope = 0; slope < 5; slope++) {
			if (slope == 4)
				skipSlope5 = !skipSlope5;

			if (slope != 4 || skipSlope5) {
				auto strPos = (str.length() + currentXPos[slope]) % str.length();
				if (str[strPos] == '#')
					treeCounter[slope]++;
				currentXPos[slope] += (slope * 2) % 8 + 1;
			}
		}
	}

	long long int product = 1;
	for (int i = 0; i < 5; i++) {
		std::cout << treeCounter[i] << std::endl;
		product *= treeCounter[i];
	}
	std::cout << product << std::endl;
}
