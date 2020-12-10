#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::vector<int> inputs;

	while (std::cin >> n)
		inputs.push_back(n);

	std::sort(inputs.begin(), inputs.end());

	auto oneC = 0;
	auto threeC = 0;
	auto previous = 0;
	
	for (int var : inputs)
	{
		if (var - previous == 1)
			oneC++;
		else if (var - previous == 3)
			threeC++;
		else if (var - previous > 3)
			break;
		previous = var;
	}
	threeC++;
	auto res = oneC* threeC;

	std::cout << res << std::endl;
}