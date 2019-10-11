#pragma once
#include <vector>
using namespace std;

std::vector<int> high_prec_multiply(vector<int> num1, vector<int> num2, int unit = 1) 
{
	long long precision = pow(10, unit);
	vector<int> rst(num1.size() + num2.size(), 0);
	for (int i1 = 0; i1 < num1.size(); i1++)
	{
		for (int i2 = 0; i2 < num2.size(); i2++)
		{
			rst[i1 + i2] += num1[i1] * num2[i2];
			rst[i1 + i2 + 1] += rst[i1 + i2] / precision;
			rst[i1 + i2] %= precision;
		}
	}
	while (rst.size() > 1 && rst[rst.size() - 1] == 0)
		rst.pop_back();
	return rst;
}