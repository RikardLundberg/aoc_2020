#include <iostream>
#include <string>
#include <vector>

enum MaskBit {
    X, ZERO, ONE
};

class memory {
public:
    std::vector<int> modAddress;
    std::vector<long long int> toVal;
};

std::string To36BitBinary(int val);
int main()
{
    MaskBit mask[36] = {};
    memory mem;

    std::string input;
    while (std::getline(std::cin, input) && input != "eof")
    {
        if (input.substr(0, 3) == "mem") 
        {
            input = input.substr(input.find('[')+1);
            auto address = std::stoi(input.substr(0, input.find(']')));
            auto val = std::stoi(input.substr(input.find_last_of(' ') + 1));
            if (val == 119)
            {
                std::string hej;
            }
            int a[36] = {0};
            for (int i = 35; val > 0; i--)
            {
                a[i] = val % 2;
                val = val / 2;
            }

            for (int i = 0; i < 36; i++)
            {
                if (mask[i] == ONE)
                    a[i] = 1;
                else if (mask[i] == ZERO)
                    a[i] = 0;
            }

            long long int newVal = 0;
            long long posWorth = 1;
            for (int i = 35; i >= 0; i--)
            {
                long long add = (a[i]);
                newVal += add * posWorth;
                posWorth *= 2;
            }

            if (newVal < 0)
            {
                std::string hej;
            }

            auto pos = std::find(mem.modAddress.begin(), mem.modAddress.end(), address);
            if (pos != mem.modAddress.end())
                mem.toVal[std::distance(mem.modAddress.begin(), pos)] = newVal;
            else 
            {
                mem.modAddress.push_back(address);
                mem.toVal.push_back(newVal);
            }
        }
        else 
        {
            for (int i = 0; i < 36; i++)
            {
                auto newChar = input.substr(input.find_last_of(' ')+1)[i];
                if (newChar == 'X')
                    mask[i] = X;
                else if (newChar == '0')
                    mask[i] = ZERO;
                else if (newChar == '1')
                    mask[i] = ONE;
            }
        }
    }

    long long sum = 0;
    for (long long val : mem.toVal)
        sum += val;

    std::cout << sum << std::endl;
}

std::string To36BitBinary(int val)
{
    std::string res;

    

    return res;
}