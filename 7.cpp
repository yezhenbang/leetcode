#include "pch.h"

/*  ##description
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution7
{
public:
	const int max = 2147483647;
	const int min = -2147483647 - 1;

	/*4 ms	8.3 MB*/
	int reverse(int x)
	{
		int rst = 0;
		while (x != 0)
		{
			int a = x % 10;
			x /= 10;
			if (rst > max / 10 || (rst == max / 10 && a > 7))
				return 0;
			if (rst < min / 10 || (rst == min / 10 && a < -8))
				return 0;
			rst = rst * 10 + a;
		}
		return rst;
	}


/*执行用时 :12 ms
内存消耗 :8.2 MB*/

	/*
	int max[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};

	int reverse(int x)
	{
		if (x == 0) return x;
		int rst = 0;
		int is_over = 0;
		if (x > 0)
		{
			max[9] = 7;
		}

		int index = 0;
		while (x != 0)
		{
			int a = x % 10;
			x /= 10;
			if (is_over == 0)
			{
				if (abs(a) > max[index] - 0)
					is_over = 1;
				else if (abs(a) < max[index] - 0)
					is_over = -1;
			}
			if (index == 9 && is_over == 1)
			{
				return 0;
			}
			index++;
			rst = rst * 10 + a;
		}
		return rst;
	}*/
};

TEST(leetcode, 7)
{
	Solution7 s;
	cout << s.reverse(2147400);
}
