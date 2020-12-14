#include <iostream>
#include <string>
#include <vector>

enum MaskBit {
    ZERO, ONE, X
};

class memory {
public:
    std::vector<long long int> modAddress;
    std::vector<long long int> toVal;
};

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

            MaskBit a[36] = {};
            for (int i = 35; address > 0; i--)
            {
                auto tmp = address % 2;
                a[i] = tmp == 1 ? ONE : ZERO;
                address = address / 2;
            }
            
            for (int i = 0; i < 36; i++)
            {
                if (mask[i] == ONE)
                    a[i] = ONE;
                else if (mask[i] == X)
                    a[i] = X;
            }
            
            
            std::vector<std::vector<MaskBit>> allAddresses;
            std::vector<std::vector<MaskBit>> permAddresses;

            std::vector<MaskBit> aTmp;
            for (int i = 0; i < 36; i++)
                aTmp.push_back(a[i]);

            allAddresses.push_back(aTmp);
            bool containsX = true;

            while (containsX) {
                containsX = false;
                std::vector<std::vector<MaskBit>> newAddresses;
                for (auto tmpAdd : allAddresses) {
                    std::vector<MaskBit> newAdd = tmpAdd;
                    bool currentContainsX = false;
                    for (int i = 0; i < 36; i++)
                    {
                        if (tmpAdd[i] == X)
                        {
                            containsX = true;
                            currentContainsX = true;
                            newAdd[i] = ZERO;
                            newAddresses.push_back(newAdd);
                            newAdd[i] = ONE;
                            newAddresses.push_back(newAdd);
                            break;
                        }
                    }
                    if (!currentContainsX)
                        permAddresses.push_back(newAdd);
                }
                allAddresses = newAddresses;
            }

            for (auto mbAdd : permAddresses) {
                long long int wtAdd = 0;
                long long posWorth = 1;
                for (int i = 35; i >= 0; i--)
                {
                    wtAdd += mbAdd[i] * posWorth;
                    posWorth *= 2;
                }

                if (wtAdd < 0)
                {
                    std::string hej;
                }

                auto pos = std::find(mem.modAddress.begin(), mem.modAddress.end(), wtAdd);
                if (pos != mem.modAddress.end())
                    mem.toVal[std::distance(mem.modAddress.begin(), pos)] = val;
                else
                {
                    mem.modAddress.push_back(wtAdd);
                    mem.toVal.push_back(val);
                }
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