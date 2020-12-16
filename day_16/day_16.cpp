#include <iostream>
#include <vector>
#include <string>

void readInput(int *validNumbers, std::vector<std::vector<int>> &nearbyTickets);
int main()
{
    int validNumbers[1000] = {};
    std::vector<std::vector<int>> nearbyTickets;
    readInput(validNumbers, nearbyTickets);

    auto invalidSum = 0;
    for (auto ticket : nearbyTickets)
        for (auto val : ticket)
            if (!validNumbers[val])
                invalidSum += val;

    std::cout << invalidSum << std::endl;
}

void readInput(int* validNumbers, std::vector<std::vector<int>>& nearbyTickets)
{
    std::string input;
    while (std::getline(std::cin, input) && input != "")
    {
        input = input.substr(input.find(':') + 2);
        auto firstInterval = input.substr(0, input.find(' '));
        auto secondInterval = input.substr(input.find_last_of(' ') + 1);
        for (int i = std::stoi(firstInterval.substr(0, firstInterval.find('-'))); i <= std::stoi(firstInterval.substr(firstInterval.find('-') + 1)); i++)
            validNumbers[i] = 1;
        for (int i = std::stoi(secondInterval.substr(0, secondInterval.find('-'))); i <= std::stoi(secondInterval.substr(secondInterval.find('-') + 1)); i++)
            validNumbers[i] = 1;
    }

    std::getline(std::cin, input);
    std::getline(std::cin, input);
    std::getline(std::cin, input);
    std::getline(std::cin, input);
    while (std::getline(std::cin, input) && input != "eof")
    {
        std::vector<int> ticket;
        while (input.find(',') != std::string::npos) 
        {
            ticket.push_back(std::stoi(input.substr(0, input.find(','))));
            input = input.substr(input.find(',')+1);
        }
        ticket.push_back(std::stoi(input));
        nearbyTickets.push_back(ticket);
    }
}
