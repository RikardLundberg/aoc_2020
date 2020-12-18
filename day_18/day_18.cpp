#include <iostream>
#include <string>

long long evaluateExpr(std::string expr);
int main()
{
	long long sum = 0;
	std::string input;
	while (std::getline(std::cin, input) && input != "eof")
	{
		while (std::find(input.begin(), input.end(), '(') != input.end())
		{
			auto paraEnd = input.find(')');
			auto tmpStr = input.substr(0, paraEnd);
			auto paraStart = tmpStr.find_last_of('(');
			auto paraExpr = tmpStr.substr(paraStart+1);
			auto evalExpr = evaluateExpr(paraExpr);
			auto head = input.substr(0, paraStart);
			//auto tail = input.back() == paraEnd ? "" : input.substr(paraEnd + 1);
			auto tail = input.substr(paraEnd).size() > 1 ? input.substr(paraEnd + 1) : "";
			input = head + std::to_string(evalExpr) + tail;
		}

		sum += evaluateExpr(input);
	}

    std::cout << sum << std::endl;
}

long long evaluateExpr(std::string expr)
{
	long long retVal = 0;
	bool operatorIsAdd = true;
	while (std::find(expr.begin(), expr.end(), ' ') != expr.end())
	{
		auto tmp = std::stoi(expr.substr(0, expr.find(' ')));
		retVal = operatorIsAdd ? retVal + tmp : retVal * tmp;
		expr = expr.substr(expr.find(' ')+1);
		operatorIsAdd = expr.substr(0, expr.find(' ')) == "+";
		expr = expr.substr(expr.find(' ')+1);
	}
	retVal = operatorIsAdd ? retVal + std::stoi(expr) : retVal * std::stoi(expr);
	return retVal;
}