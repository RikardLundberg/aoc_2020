#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void TranslateAnswers(std::string val, std::vector<char>& answers, bool initPopulation);
int main()
{
	int totalAnswerCount = 0;
	std::vector<char> answers;
	std::string input;
	bool initPopulation = true;
	while (std::getline(std::cin, input) && input != "eof") {
		if (input == "")
		{
			totalAnswerCount += answers.size();
			answers.clear();
			initPopulation = true;
			continue;
		}
		TranslateAnswers(input, answers, initPopulation);
		initPopulation = false;
	}

	std::cout << totalAnswerCount << std::endl;
}

void TranslateAnswers(std::string val, std::vector<char>& answers, bool initPopulation)
{
	std::vector<char> newAnswers;
	for (char ch : val)
	{
		if (std::count(answers.begin(), answers.end(), ch) || initPopulation)
			newAnswers.push_back(ch);
	}
	answers.clear();
	answers = newAnswers;
}