#include <iostream>
#include <vector>
#include <algorithm>

void compareInputs(std::vector<int> inputs, int& a, int& b);

int main()
{
	int n;
	std::vector<int> inputs;

	while (std::cin >> n)
		inputs.push_back(n);

	std::sort(inputs.begin(), inputs.end());

	int a, b;
	compareInputs(inputs, a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << a * b << std::endl;
}

void compareInputs(std::vector<int> inputs, int& a, int& b)
{
	for (int input : inputs)
	{
		for (int i = 0; i < inputs.size(); i++) {
			auto sum = input + inputs[i];
			if (sum == 2020) {
				a = input;
				b = inputs[i];
				return;
			}
			else if (sum > 2020)
				break;
		}
	}
}