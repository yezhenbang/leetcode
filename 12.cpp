#include "pch.h"

/*  ##description
	罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/integer-to-roman
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
*/

class Solution12
{
public:

/*16 ms	8.5 MB*/
	string intToRoman(int num)
	{
		string rst;
		char roman[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

		int index = 0;
		while (num > 0)
		{
			int a = num % 10;
			num /= 10;
			if (a == 9)
			{
				rst = roman[index + 2] + rst;
				a = 1;
			}
			if (a == 8)
			{
				rst = roman[index] + rst;
				a--;
			}
			if (a == 7)
			{
				rst = roman[index] + rst;
				a--;
			}
			if (a == 6)
			{
				rst = roman[index] + rst;
				a--;
			}
			if (a == 5)
			{
				rst = roman[index + 1] + rst;
				a = 0;
			}
			if (a == 4)
			{
				rst = roman[index + 1] + rst;
				a = 1;
			}
			if (a == 3)
			{
				rst = roman[index] + rst;
				a--;
			}
			if (a == 2)
			{
				rst = roman[index] + rst;
				a--;
			}
			if (a == 1)
			{
				rst = roman[index] + rst;
				a--;
			}
			index += 2;
		}
		return rst;
	}


	void init()
	{
		Roman.push_back(pair<int, string>(1, "I"));
		Roman.push_back(pair<int, string>(4, "IV"));
		Roman.push_back(pair<int, string>(5, "V"));
		Roman.push_back(pair<int, string>(9, "IX"));
		Roman.push_back(pair<int, string>(10, "X"));
		Roman.push_back(pair<int, string>(40, "XL"));
		Roman.push_back(pair<int, string>(50, "L"));
		Roman.push_back(pair<int, string>(90, "XC"));
		Roman.push_back(pair<int, string>(100, "C"));
		Roman.push_back(pair<int, string>(400, "CD"));
		Roman.push_back(pair<int, string>(500, "D"));
		Roman.push_back(pair<int, string>(900, "CM"));
		Roman.push_back(pair<int, string>(1000, "M"));
	}

	/*32 ms	15.5 MB	*/
	string intToRoman2(int num)
	{
		init();
		string rst;
		for (int i = Roman.size() - 1; i >= 0; i--)
		{
			while (num >= Roman[i].first)
			{
				rst += Roman[i].second;
				num -= Roman[i].first;
			}
		}
		return rst;
	}

private:
	vector<pair<int, string>> Roman;
};

TEST(leetcode, 12)
{
	Solution12 s;
	int a;
	a = 1;
	EXPECT_STREQ(s.intToRoman(a).c_str(), s.intToRoman2(a).c_str()) << a;
	a = 4;
	EXPECT_STREQ(s.intToRoman(a).c_str(), s.intToRoman2(a).c_str()) << a;
	a = 9;
	EXPECT_STREQ(s.intToRoman(a).c_str(), s.intToRoman2(a).c_str()) << a;
	a = 58;
	EXPECT_STREQ(s.intToRoman(a).c_str(), s.intToRoman2(a).c_str()) << a;
	a = 1994;
	EXPECT_STREQ(s.intToRoman(a).c_str(), s.intToRoman2(a).c_str()) << a;
	a = 3789;
	EXPECT_STREQ(s.intToRoman(a).c_str(), s.intToRoman2(a).c_str()) << a;
	a = 3999;
	EXPECT_STREQ(s.intToRoman(a).c_str(), s.intToRoman2(a).c_str()) << a;
}
