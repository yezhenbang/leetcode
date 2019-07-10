#include "pch.h"

/*  ##description
	给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution22 {
public:
	vector<string> generateParenthesis(int n) {
		rst.clear();
		generate("", 0, n);
		return rst;
	}
private:
	vector<string> rst;

	void generate(string s, int pre, int last)
	{
		if (pre == 0 && last == 0)
		{
			rst.push_back(s);
			return;
		}
		if (last > 0)
			generate(s + '(', pre + 1, last - 1);
		if (pre > 0)
			generate(s + ')', pre - 1, last);
	}
};

TEST(leetcode, 22)
{
	Solution22 s;
	showVector<string>(s.generateParenthesis(0));
	showVector<string>(s.generateParenthesis(1));
	showVector<string>(s.generateParenthesis(3));
	showVector<string>(s.generateParenthesis(5));
}
