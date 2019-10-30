#pragma once
#include <string>
#include <vector>

inline int calcUnit(const char& ch, int& num1, int& num2)
{
	switch (ch) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	case '/': return num1 / num2;
	default:
		throw std::exception("Invalid Expression.");
	}
}

inline bool isNum(char ch)
{
	return (ch >= '0' && ch <= '9');
}

long long CalcMidExpression(const std::string& exp)
{
	std::vector<int> nums;
	std::vector<char> opers;

	size_t i = 0;
	for (; i < exp.size(); i++) {
		switch (exp[i]) {
		case '(':
			opers.push_back(exp[i]);
			break;
		case ')':
			while (!opers.empty() && opers.back() != '(') {
				if (nums.size() < 2)
					throw std::exception("Invalid Expression.");

				int num2 = nums.back();
				nums.pop_back();
				nums.back() = calcUnit(opers.back(), nums.back(), num2);
				opers.pop_back();
			}
			if (opers.empty())
				throw std::exception("Invalid Expression.");
			opers.pop_back();
			break;
		case '+':
		case '-':
			while (!opers.empty() && (opers.back() == '*' || opers.back() == '/')) {
				if (nums.size() < 2)
					throw std::exception("Invalid Expression.");
				
				int num2 = nums.back();
				nums.pop_back();
				nums.back() = calcUnit(opers.back(), nums.back(), num2);
				opers.pop_back();
			}
			opers.push_back(exp[i]);
			break;
		case '*':
		case '/':
			opers.push_back(exp[i]);
			break;
		default:
			if (!isNum(exp[i]))
				throw std::exception("Invalid Expression.");
			int num = 0;
			while (i < exp.size() && isNum(exp[i])) {
				num = num * 10 + (exp[i] - '0');
				i++;
			}
			i--;
			nums.push_back(num);
		}
	}

	while (!opers.empty()) {
		if (nums.size() < 2)
			throw std::exception("Invalid Expression.");

		int num2 = nums.back();
		nums.pop_back();
		nums.back() = calcUnit(opers.back(), nums.back(), num2);
		opers.pop_back();
	}

	if (nums.size() != 1)
		throw std::exception("Invalid Expression.");

	return nums.back();
}
