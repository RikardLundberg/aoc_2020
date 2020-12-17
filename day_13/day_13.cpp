#include <iostream>
#include <vector>
#include <string>

void getInput(std::vector<int> &buses, std::vector<int>& poses);
int main()
{
    //long long int ts = 100000000000000;
    long long int ts = 0;
    std::vector<int> buses;
    std::vector<int> poses;
    getInput(buses, poses);

    /*int largeBus = buses[3];
    while (!((ts + poses[3]) % buses[3] == 0))
        ts++;
        */

    int busIndex = 3;
    int busIndex2 = 7;

    int jump = buses[busIndex] * buses[busIndex2];
    int startValue = buses[busIndex];
    bool foundEquilibrium = false;
    while (!foundEquilibrium)
    {
        startValue++;
        if (startValue % buses[busIndex] == poses[busIndex]
            && startValue % buses[busIndex2] == poses[busIndex2])
            break;
    }

    ts = jump - startValue;
    long long correctTs = 0;
    while (true)
    {
        for (int i = 0; i < buses.size(); i++)
        {
            if (i == busIndex || i == busIndex2)
                continue;
            if (( ts+ poses[i]) % buses[i] != 0)
                break;
            //will not work if picked last bus as initJump. Eh, just don't.
            if (i == buses.size() - 1)
                correctTs = ts;
        }
        if (correctTs)
            break;
        ts += jump;
    }

    std::cout << correctTs << std::endl;
}


void getInput(std::vector<int> &buses, std::vector<int> &poses)
{
    std::string busLine;
    std::cin >> busLine;
    int pos = 0;

    while (busLine.find(',') != std::string::npos)
    {
        std::string potBus = busLine.substr(0, busLine.find(','));
        if (potBus != "x") {
            buses.push_back(std::stoi(potBus));
            poses.push_back(pos);
        }
        busLine = busLine.substr(busLine.find(',') + 1);
        pos++;
    }
    if (busLine != "x") {
        buses.push_back(std::stoi(busLine));
        poses.push_back(pos);
    }
}