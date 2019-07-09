#include "pch.h"

/*  ##description
	给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
m1i1s2i1s2i1p2i1
m1i1s*i1s*.*p*i

m1i1s*i1s*
p = "mis*is*p*."
输出: false

aabccca
aabc*ca
"a*s*d*fg*"

"aaa" = "a*b*a"
"aaaaab" = "a*b*ab"

"aaabcabc" <> "a*b*c*abcabc"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution10 {
public:
	/*0 ms	8.7 MB*/
	bool isMatch(string s, string p) {
		int s_len = s.length();
		int p_len = p.length();
		bool** dp = new bool*[s_len + 1];
		for (int i = 0; i < s_len + 1; i++)
		{
			dp[i] = new bool[p_len + 1];
			for (int j = 0; j < p_len + 1; j++)
				dp[i][j] = false;
		}

		// dp[s的前x个字符][p的前y组字符] = 是否满足
		dp[0][0] = true;
		int cnt = 0;
		for (int p_i = 1; p_i <= p_len; p_i++)
		{
			cnt++;
			char ch = p[p_i - 1];
			bool is_any = false;
			if (p_i + 1 <= p_len && p[p_i] == '*')
			{
				p_i++;
				is_any = true;
				dp[0][cnt] = dp[0][cnt - 1];
			}

			for (int s_i = 1; s_i <= s_len; s_i++)
			{
				if (s[s_i - 1] == ch || ch == '.')   // 字符匹配的
				{
					if (is_any)
					{
						// 用或者不用
						dp[s_i][cnt] = dp[s_i - 1][cnt - 1] || dp[s_i][cnt - 1];
						if (s_i > 1 && (s[s_i - 2] == ch || ch == '.'))
							dp[s_i][cnt] = dp[s_i][cnt] || dp[s_i - 1][cnt]; // 用多次
					}
					else
					{
						dp[s_i][cnt] = dp[s_i - 1][cnt - 1];
					}
				}
				else  //字符不匹配的
				{
					if (is_any)
					{
						// 不用
						dp[s_i][cnt] = dp[s_i][cnt - 1];
					}
					else
						dp[s_i][cnt] = false;
				}
			}
		}

		bool rst = dp[s_len][cnt];
		for (int i = 0; i < s_len + 1; i++)
			delete[] dp[i];
		delete[] dp;

		return rst;
	}
};

TEST(leetcode, 10)
{
	Solution10 s;
	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("ab", ".*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;
	cout << s.isMatch("mississippi", "mis*is*p*.") << endl;
	cout << s.isMatch("mississippi", "mis*is*ip*.") << endl;
	cout << s.isMatch("aaa", "a*b*a") << endl;
	cout << s.isMatch("aaaaab", "a*b*ab") << endl;
	cout << s.isMatch("aaabcabc", "a*b*c*abcabc") << endl;
	cout << s.isMatch("aaabcabc", ".*a.c.b*c*") << endl;
	cout << s.isMatch("aaabcabc", ".*a.c.bc*") << endl;
	cout << s.isMatch("a", "") << endl;
	cout << s.isMatch("", ".*") << endl;
	cout << s.isMatch("", "a*") << endl;
}
