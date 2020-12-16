#include <iostream>
#include <string>

class ship
{
public:
    int currDirection = 90;
    int xPos = 0;
    int yPos = 0;
};

void doShipAction(std::string action, int val, ship& ship);
int main()
{
    ship ship;
    std::string input;
    while (std::getline(std::cin, input) && input != "eof")
    {
        auto action = input.substr(0, 1);
        auto val = std::stoi(input.substr(1));
        doShipAction(action, val, ship);
    }

    std::cout << std::abs(ship.xPos) + std::abs(ship.yPos) << std::endl;
}

void doShipAction(std::string action, int val, ship& ship)
{
    if (action == "N")
        ship.yPos += val;
    else if (action == "S")
        ship.yPos -= val;
    else if (action == "E")
        ship.xPos += val;
    else if (action == "W")
        ship.xPos -= val;
    else if (action == "L")
        ship.currDirection = ((ship.currDirection - val)+360) % 360;
    else if (action == "R")
        ship.currDirection = (ship.currDirection + val) % 360;
    else if (action == "F")
    {
        switch (ship.currDirection) {
        case 0:
            ship.yPos += val;
            break;
        case 90:
            ship.xPos += val;
            break;
        case 180:
            ship.yPos -= val;
            break;
        case 270:
            ship.xPos -= val;
            break;
        }
    }
}