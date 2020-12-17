#include <iostream>
#include <vector>
#include <string>
#include <chrono>

void getInput(std::vector<int> &buses, std::vector<int>& poses);
int main()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    long long int ts = 0;
    std::vector<int> buses;
    std::vector<int> poses;
    getInput(buses, poses);

    int busIndex = 3;
    int busIndex2 = 7;
    int busIndex3 = 1;

    int jump = buses[busIndex] * buses[busIndex2] * buses[busIndex3];
    int startValue = buses[busIndex];
    bool foundEquilibrium = false;
    while (!foundEquilibrium)
    {
        startValue++;
        if (startValue % buses[busIndex] == poses[busIndex]
            && startValue % buses[busIndex2] == poses[busIndex2]
            && startValue % buses[busIndex3] == poses[busIndex3])
            break;
    }

    ts = jump - startValue;
    long long correctTs = 0;
    while (true)
    {
        for (int i = 0; i < buses.size(); i++)
        {
            if (i == busIndex || i == busIndex2 || i == busIndex3)
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

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << correctTs << std::endl << std::endl << "Time elapsed = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms"<< std::endl;
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