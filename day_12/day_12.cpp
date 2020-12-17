#include <iostream>
#include <string>

class ship
{
public:
    int xPos = 0;
    int yPos = 0;
    int wp_x = 10;
    int wp_y = 1;
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
        ship.wp_y += val;
    else if (action == "S")
        ship.wp_y -= val;
    else if (action == "E")
        ship.wp_x += val;
    else if (action == "W")
        ship.wp_x -= val;
    else if (action == "L") 
    {
        auto tmp_y = ship.wp_y;
        switch (val) {
        case 270:
            ship.wp_y = ship.wp_x * -1;
            ship.wp_x = tmp_y;
            break;
        case 180:
            ship.wp_y = ship.wp_y * -1;
            ship.wp_x = ship.wp_x * -1;
            break;
        case 90:
            ship.wp_y = ship.wp_x;
            ship.wp_x = tmp_y * -1;
            break;
        }
    }
    else if (action == "R")
    {
        auto tmp_y = ship.wp_y;
        switch (val) {
        case 90:
            ship.wp_y = ship.wp_x * -1;
            ship.wp_x = tmp_y;
            break;
        case 180:
            ship.wp_y = ship.wp_y * -1;
            ship.wp_x = ship.wp_x * -1;
            break;
        case 270:
            auto tmp_y = ship.wp_y;
            ship.wp_y = ship.wp_x;
            ship.wp_x = tmp_y * -1;
            break;
        }
    }
    else if (action == "F")
    {
        ship.xPos += (ship.wp_x * val);
        ship.yPos += (ship.wp_y * val);
    }
}