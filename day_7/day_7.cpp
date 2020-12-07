#include <iostream>
#include <vector>
#include <string>

struct rule
{
	std::string bag;
	//two below are same size =) Engineering!
	std::vector<std::string> containers;
	std::vector<int> containerCount;
};

void findContainers(std::vector<rule> rules, std::vector<std::string> &containers, std::string bag);
int main()
{
	std::vector<rule> rules;
	std::string input;

	//fml parsing..
	while (std::getline(std::cin, input) && input != "eof") 
	{
		rule rule;
		auto bagString = input.substr(0, input.find(" contain"));
		rule.bag = bagString.substr(0, bagString.find_last_of(" "));
		auto containString = input.substr(input.find("contain ")+8);
		while (true) 
		{
			if (containString == "no other bags.")
				break;
			if (containString.find(",") != std::string::npos)
			{
				bagString = containString.substr(0, containString.find(","));
				containString = containString.substr(containString.find(",")+2);
				rule.containerCount.push_back(std::stoi(bagString.substr(0, bagString.find(" "))));
				bagString = bagString.substr(bagString.find(" ")+1);
				rule.containers.push_back(bagString.substr(0, bagString.find_last_of(" ")));
			}
			else {
				bagString = containString.substr(0, containString.find("."));
				rule.containerCount.push_back(std::stoi(bagString.substr(0, bagString.find(" "))));
				bagString = bagString.substr(bagString.find(" ")+1);
				rule.containers.push_back(bagString.substr(0, bagString.find_last_of(" ")));
				break;
			}
		}
		rules.push_back(rule);
	}

	//actual problem
	std::vector<std::string> containers;
	findContainers(rules, containers, "shiny gold");

	std::cout << containers.size() << std::endl;
}

void findContainers(std::vector<rule> rules, std::vector<std::string> &containers, std::string bag)
{
	for (rule rule : rules) 
	{
		if (std::count(rule.containers.begin(), rule.containers.end(), bag) && !std::count(containers.begin(), containers.end(), rule.bag)) {
			containers.push_back(rule.bag);
			findContainers(rules, containers, rule.bag);
		}
	}
}