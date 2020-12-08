#include <iostream>
#include <string>
#include <vector>

int attemptExecution(std::vector<std::string> instructions, std::vector<int> executedInstructions, int executionAttempt);
int main()
{
	std::vector<std::string> instructions;
	std::vector<int> executedInstructions;
	std::string input;
	while (std::getline(std::cin, input) && input != "eof")
	{
		instructions.push_back(input);
		executedInstructions.push_back(0);
	}

	int executionAttempt = 0, acc = -1;
	while(acc == -1)
		acc = attemptExecution(instructions, executedInstructions, executionAttempt++);

    std::cout << acc << std::endl;
}

int attemptExecution(std::vector<std::string> instructions, std::vector<int> executedInstructions, int executionAttempt)
{
	int sp = 0, acc = 0, modifier = 0;
	while (true)
	{
		if (sp < 0)
			return -1;
		else if (sp >= instructions.size())
			return acc;
		else if (executedInstructions[sp] == 1)
			return -1;
		auto currentInstruction = instructions[sp];
		executedInstructions[sp] = 1;
		auto cmd = currentInstruction.substr(0, currentInstruction.find(" "));
		if (modifier == executionAttempt && (cmd == "nop" || cmd == "jmp"))
			cmd = cmd == "nop" ? "jmp" : "nop";
		auto arg = std::stoi(currentInstruction.substr(currentInstruction.find(" ") + 1));
		if (cmd == "nop")
		{
			sp++;
			modifier++;
		}
		else if (cmd == "acc")
		{
			acc += arg;
			sp++;
		}
		else if (cmd == "jmp")
		{
			sp += arg;
			modifier++;
		}
	}
}