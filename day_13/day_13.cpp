#include <iostream>
#include <vector>
#include <string>

void getInput(int& ts, std::vector<int> &buses);
int main()
{
    int ts;
    std::vector<int> buses;
    getInput(ts, buses);

    int correctId = 0, minutes = 0;
    while (!correctId)
    {
        for (int bus : buses)
        {
            if ((ts+minutes) % bus == 0)
            {
                correctId = bus;
                break;
            }
        }
        if(!correctId)
            minutes++;
    }

    std::cout << correctId * minutes << std::endl;
}


void getInput(int &ts, std::vector<int> &buses)
{
    std::string busLine;
    std::cin >> ts;
    std::cin >> busLine;

    while (busLine.find(',') != std::string::npos)
    {
        std::string potBus = busLine.substr(0, busLine.find(','));
        if (potBus != "x")
            buses.push_back(std::stoi(potBus));
        busLine = busLine.substr(busLine.find(',') + 1);
    }
    if (busLine != "x")
        buses.push_back(std::stoi(busLine));
}