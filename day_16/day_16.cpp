#include <iostream>
#include <vector>
#include <string>

void readInput(int* validNumbers, std::vector<std::vector<int>>& positions, std::vector<int>& yourTicket, std::vector<std::vector<int>>& nearbyTickets);
int main()
{
	int validNumbers[1000] = {};
	std::vector<std::vector<int>> positions;
	std::vector<int> yourTicket;
	std::vector<std::vector<int>> nearbyTickets;
	readInput(validNumbers, positions, yourTicket, nearbyTickets);

	std::vector<std::vector<int>> validNearbyTickets;
	for (auto ticket : nearbyTickets) {
		bool invalid = false;
		for (auto val : ticket)
			if (!validNumbers[val]) {
				invalid = true;
				break;
			}
		if (!invalid)
			validNearbyTickets.push_back(ticket);
	}

	int matches[20] = {};
	bool shouldContinue = true;

	while (shouldContinue) {
		shouldContinue = false;
		for (int i = 0; i < 20; i++) {
			if (matches[i] != 0)
				continue;
			auto remainingPositions = positions;
			for (auto ticket : validNearbyTickets) {
				for (int j = 0; j < remainingPositions.size(); j++)
				{
					if (remainingPositions[j].end() == std::find(remainingPositions[j].begin(), remainingPositions[j].end(), ticket[i]))
						remainingPositions.erase(remainingPositions.begin() + j);
				}
				if (remainingPositions.size() == 1) {
					matches[i] = remainingPositions[0].back() - remainingPositions[0][0];
					positions.erase(std::find(positions.begin(), positions.end(), remainingPositions[0]));
					break;
				}
			}
			if (matches[i] == 0)
				shouldContinue = true;
		}
	}

	long long multiVal = 1;
	for (int i = 0; i < 20; i++)
	{
		switch (matches[i]) {
		case 901:
		case 942:
		case 922:
		case 915:
		case 926:
		case 918:
			multiVal *= yourTicket[i];
			break;
		}
	}

	std::cout << multiVal << std::endl;
}

void readInput(int* validNumbers, std::vector<std::vector<int>>& positions, std::vector<int>& yourTicket, std::vector<std::vector<int>>& nearbyTickets)
{
	std::string input;
	while (std::getline(std::cin, input) && input != "")
	{
		std::vector<int> position;
		input = input.substr(input.find(':') + 2);
		auto firstInterval = input.substr(0, input.find(' '));
		auto secondInterval = input.substr(input.find_last_of(' ') + 1);
		for (int i = std::stoi(firstInterval.substr(0, firstInterval.find('-'))); i <= std::stoi(firstInterval.substr(firstInterval.find('-') + 1)); i++)
		{
			validNumbers[i] = 1;
			position.push_back(i);
		}
		for (int i = std::stoi(secondInterval.substr(0, secondInterval.find('-'))); i <= std::stoi(secondInterval.substr(secondInterval.find('-') + 1)); i++)
		{
			validNumbers[i] = 1;
			position.push_back(i);
		}
		positions.push_back(position);
	}

	std::getline(std::cin, input);
	std::getline(std::cin, input);
	while (input.find(',') != std::string::npos)
	{
		yourTicket.push_back(std::stoi(input.substr(0, input.find(','))));
		input = input.substr(input.find(',') + 1);
	}
	yourTicket.push_back(std::stoi(input));
	std::getline(std::cin, input);
	std::getline(std::cin, input);
	while (std::getline(std::cin, input) && input != "eof")
	{
		std::vector<int> ticket;
		while (input.find(',') != std::string::npos)
		{
			ticket.push_back(std::stoi(input.substr(0, input.find(','))));
			input = input.substr(input.find(',') + 1);
		}
		ticket.push_back(std::stoi(input));
		nearbyTickets.push_back(ticket);
	}
}
