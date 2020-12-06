#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void TranslateAnswers(std::string val, std::vector<char> &answers);
int main()
{
	int totalAnswerCount = 0;
	std::vector<char> answers;
	std::string input;
	while (std::getline(std::cin, input) && input != "eof") {
		if (input == "")
		{
			totalAnswerCount += answers.size();
			answers.clear();
			continue;
		}
		TranslateAnswers(input, answers);
	}

	std::cout << totalAnswerCount << std::endl;
}

void TranslateAnswers(std::string val, std::vector<char>& answers)
{
	for (char ch : val) 
	{
		if (!std::count(answers.begin(), answers.end(), ch))
			answers.push_back(ch);
	}
}