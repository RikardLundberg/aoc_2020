#include <iostream>
#include <string>
#include <vector>

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
			auto paraExpr = tmpStr.substr(paraStart + 1);
			auto evalExpr = evaluateExpr(paraExpr);
			auto head = input.substr(0, paraStart);
			auto tail = input.substr(paraEnd).size() > 1 ? input.substr(paraEnd + 1) : "";
			input = head + std::to_string(evalExpr) + tail;
		}

		sum += evaluateExpr(input);
	}

	std::cout << sum << std::endl;
}

enum op
{
	ADD, MUL
};

long long evaluateExpr(std::string expr)
{
	long long retVal = 0;

	std::vector<long long> vals;
	std::vector<op> ops;

	bool nextIsOp = false;
	while (std::find(expr.begin(), expr.end(), ' ') != expr.end())
	{
		auto tmp = expr.substr(0, expr.find(' '));
		if (nextIsOp)
		{
			if (tmp == "+")
				ops.push_back(ADD);
			else
				ops.push_back(MUL);
		}
		else
			vals.push_back(std::stoi(tmp));
		expr = expr.substr(expr.find(' ') + 1);
		nextIsOp = !nextIsOp;
	}
	vals.push_back(std::stoi(expr));

	for (int i = 0; i < ops.size(); i++)
	{
		if (ops[i] == ADD)
			vals[i + 1] = vals[i + 1] + vals[i];
	}

	retVal = vals.back();
	for (int i = 0; i < ops.size(); i++)
	{
		if (ops[i] == MUL)
			retVal *= vals[i];
	}

	return retVal;
}