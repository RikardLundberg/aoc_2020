#include <iostream>
#include <string>
#include <vector>


int main()
{
	int acc = 0;

	std::vector<std::string> instructions;
	std::vector<int> executedInstructions;
	std::string input;
	while (std::getline(std::cin, input) && input != "eof")
	{
		instructions.push_back(input);
		executedInstructions.push_back(0);
	}

	int sp = 0;
	while (executedInstructions[sp] != 1)
	{
		auto currentInstruction = instructions[sp];
		executedInstructions[sp] = 1;
		auto cmd = currentInstruction.substr(0, currentInstruction.find(" "));
		auto arg = std::stoi(currentInstruction.substr(currentInstruction.find(" ")+1));
		if (cmd == "nop")
			sp++;
		else if (cmd == "acc") 
		{
			acc += arg;
			sp++;
		}
		else if (cmd == "jmp")
			sp += arg;
	}

    std::cout << acc << std::endl;
}