#include "pch.h"

/*  ##description
	给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution17 {
public:
/*4 ms	8.7 MB*/
	vector<string> letterCombinations(string digits) {
		vector<string> a = {""};
		vector<string> b;
		if (digits.empty())
			return b;
		gogogo(digits, 0, a, b);
		if (a.empty())
			return b;
		return a;
	}

private:
	void gogogo(string& s, int i, vector<string>& src, vector<string>& dst)
	{
		dst.clear();
		if (i >= s.length())
			return;
		for (auto& word : src)
		{
			dst.push_back(word + button[s[i] - '0'][0]);
			dst.push_back(word + button[s[i] - '0'][1]);
			dst.push_back(word + button[s[i] - '0'][2]);
			if (s[i] == '7' || s[i] == '9')
				dst.push_back(word + button[s[i] - '0'][3]);
		}
		gogogo(s, i + 1, dst, src);
	}

	char button[10][4] = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
};

TEST(leetcode, 17)
{
	Solution17 s;
	auto rst = s.letterCombinations("79");
	for (auto i:rst)
	{
		cout << i << " ";
	}
}
