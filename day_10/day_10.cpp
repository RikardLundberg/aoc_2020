#include <iostream>
#include <vector>
#include <algorithm>

void chainAdapters(std::vector<int> inputs, long long& iterations, int previous);
void findBottlenecks(std::vector<int> inputs, std::vector<int>& bnecks);
int main()
{
	int n;
	std::vector<int> inputs;

	while (std::cin >> n)
		inputs.push_back(n);

	std::sort(inputs.begin(), inputs.end());

	std::vector<int> bnecks;
	findBottlenecks(inputs, bnecks);

	long long output = 1;

	int lowEnd = 0;
	int startChain = 0;
	for (int i = 1; i < bnecks.size(); i++)
	{
		std::vector<int> inputSeg;
		for (int j = lowEnd; j < bnecks[i]; j++)
			inputSeg.push_back(inputs[j]);

		long long iterations = 0;
		chainAdapters(inputSeg, iterations, startChain);
		output *= iterations;
		lowEnd = bnecks[i];
		startChain = inputs[bnecks[i]];
	}

	std::vector<int> inputSeg;
	for (int j = lowEnd; j < inputs.size(); j++)
		inputSeg.push_back(inputs[j]);

	long long iterations = 0;
	chainAdapters(inputSeg, iterations, startChain);
	output *= iterations;

	std::cout << output << std::endl;
}

void findBottlenecks(std::vector<int> inputs, std::vector<int>& bnecks)
{
	for (int i = 0; i < inputs.size(); i++)
	{
		if ((i == 0 || inputs[i] - inputs[i - 1] == 3)
			&& (i == inputs.size()-1 || inputs[i + 1] - inputs[i] == 3))
			bnecks.push_back(i);
	}
}

void chainAdapters(std::vector<int> inputs, long long& iterations, int previous)
{
	for (int var : inputs)
	{
		if (var <= previous)
			continue;
		auto diff = var - previous;
		if (diff <= 3) {
			if (var == inputs.back()) {
				iterations++;
				return;
			}
			chainAdapters(inputs, iterations, var);
		}
		else if (diff > 3)
			break;
	}
}