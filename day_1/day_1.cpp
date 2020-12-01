#include <iostream>
#include <vector>
#include <algorithm>

void compareInputs(std::vector<int> inputs, int& a, int& b, int &c);

int main()
{
	int n;
	std::vector<int> inputs;

	while (std::cin >> n)
		inputs.push_back(n);

	std::sort(inputs.begin(), inputs.end());

	int a, b, c;
	compareInputs(inputs, a, b, c);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	std::cout << a * b * c << std::endl;
}

void compareInputs(std::vector<int> inputs, int& a, int& b, int &c)
{
	for (int input : inputs)
	{
		for (int i = 0; i < inputs.size(); i++) {
			auto preSum = input + inputs[i];
			if (preSum > 2020)
				break;
			for (int j = 0; j < inputs.size(); j++) {
				auto sum = preSum + inputs[j];
				if (sum == 2020) {
					a = input;
					b = inputs[j];
					c = inputs[i];
					return;
				}
				else if (sum > 2020)
					break;
			}
		}
	}
}