#include <iostream>
#include <vector>

class mem {
	//incredibly stupid solution for an incredibly stupid game
	//takes hours to execute, but works
	//could be optimized A LOT by multiple lists and/or sorting
	//Eh
public:
	std::vector<int> nbr;
	std::vector<int> lastSpoken;
};

int playGame(mem& mem, int turns, int currentTurn);
void loadMem(mem& mem);
int main()
{
	mem mem;
	int turns = 30000000;
	loadMem(mem);
	int startTurn = mem.nbr.size();
	int finalNbr = playGame(mem, turns, startTurn);
	std::cout << finalNbr << std::endl;
}

int playGame(mem& mem, int turns, int currentTurn)
{
	int previousNumber = mem.nbr[currentTurn - 1];
	while (currentTurn < turns)
	{
		auto pos = std::find(mem.nbr.begin(), mem.nbr.end(), previousNumber);
		auto age = currentTurn;
		if (pos == mem.nbr.end())
		{
			mem.nbr.push_back(previousNumber);
			mem.lastSpoken.push_back(currentTurn);
			age = 0;
		}
		else 
		{
			age -= mem.lastSpoken[std::distance(mem.nbr.begin(), pos)];
			mem.lastSpoken[std::distance(mem.nbr.begin(), pos)] = currentTurn;
		}
		previousNumber = age;
		currentTurn++;
	}
	return previousNumber;
}

void loadMem(mem& mem)
{
	std::vector<int> inputs = { 0,13,16,17,1,10,6 };
	for (int i = 0; i < inputs.size(); i++) {
		mem.nbr.push_back(inputs[i]);
		mem.lastSpoken.push_back(i+1);
	}
}
