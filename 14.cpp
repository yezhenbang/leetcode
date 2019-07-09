#include "pch.h"

/*  ##description
	编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution14 {
public:

	string commonPrefix(string& s1, string& s2)
	{
		int i;
		for (i = 0; i < min(s1.length(), s2.length()); i++)
		{
			if (s1[i] != s2[i])
				break;
		}
		return s1.substr(0, i);
	}
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
/*12 ms	8.9 MB*/
		/*sort(strs.begin(), strs.end());
		return commonPrefix(strs[0], strs.back());*/
/*4 ms	8.7 MB*/
		string rst = strs[0];
		for (unsigned int i = 1; i < strs.size(); i++)
			rst = commonPrefix(rst, strs[i]);
		return rst;
	}
};

TEST(leetcode, 14)
{
	vector<string> strs = { "aaaa", "a", "aaa"};
	Solution14 s;
	cout << s.longestCommonPrefix(strs);
}
