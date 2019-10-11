#include "pch.h"

/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//#include "util\hp_multiply.h"
/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43]
 */

// @lc code=start
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

class Solution {
public:
	string multiply(string num1, string num2) {
		string rst;
		vector<int> vec_num1, vec_num2;
		convertNumStrToVec(num1, vec_num1);
		convertNumStrToVec(num2, vec_num2);
		vector<int> vec_rst(high_prec_multiply(vec_num1, vec_num2));
		convertNumVecToStr(vec_rst, rst);
		return rst;
	}

private:
	void convertNumStrToVec(const string& str, vector<int>& vec)
	{
		for (int i = str.length() - 1; i >= 0; i--)
			vec.push_back(str[i] - '0');
	}
	
	void convertNumVecToStr(const vector<int>& vec, string& str)
	{
		for (int i = vec.size() - 1; i >= 0; i--)
			str += to_string(vec[i]);
	}
};
// @lc code=end
TEST(leetcode, 43)
{
	Solution s;
	cout << s.multiply("2", "3") << endl;
	cout << s.multiply("123", "456") << endl;
	cout << s.multiply("22", "9") << endl;
	cout << s.multiply("2", "0") << endl;
}