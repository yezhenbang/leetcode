#include "pch.h"

/*  ##description
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	/*20 ms	8 MB*/
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x < 10) return true;
		if (x % 10 == 0) return false;

		int rev = 0;
		while (x > rev)
		{
			rev = rev * 10 + x % 10;
			x /= 10;
			if (rev == x)
				return true;
			if (rev == x / 10)
				return true;
		}
		return false;
	}
};

TEST(leetcode, 9)
{
	Solution s;

	cout << s.isPalindrome(100) << endl;
	cout << s.isPalindrome(10) << endl;
	cout << s.isPalindrome(1001) << endl;
	cout << s.isPalindrome(1000001) << endl;
}
