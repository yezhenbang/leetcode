#include "pch.h"

/*  ##description
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N

L     D     R   
E   O E   I I 
E C   I H   N
T     S     G

1: 1+k(2r-2)
2: 2
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution6 {
public:
	string convert(string s, int numRows) {
		string rst = "";
		int len = s.length();
		if (numRows == 1) return s;

		for (int i = 1; i <= min(numRows, len); i++)
		{
			int index = i - 1;
			int offset = 0;
			rst += s[index];

			while (true)
			{
				offset = 2 * (numRows - i);
				if (offset > 0) {
					index += offset;
					if (index >= len)
						break;
					rst += s[index];
				}
				offset = 2 * (i - 1);
				if (offset > 0) {
					index += offset;
					if (index >= len)
						break;
					rst += s[index];
				}
			}
		}
		return rst;
	}
};

TEST(leetcode, 6)
{
	string aa = "aT";
	Solution6 s;
	cout << s.convert(aa, 1);
}
