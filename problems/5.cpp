#include "pch.h"

/*给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*
 */

class Solution
{
public:

	/* ^*xx*$形式的其实可以看成^*X*$ 处理，就不需要再处理偶数，应该还能跳过挺多的
	 * 
	 * 执行用时 :4 ms
		内存消耗 :8.6 MB
	 */
	string longestPalindrome(string s)
	{
		if (s.length() < 2) return s;

		rst_left = 0;
		rst_len = 1;
		int len = s.length();
		for (int i = 0; i < s.length() - rst_len / 2; i++)
		{
			i = findPalindrome(s, i);
		}

		return s.substr(rst_left, rst_len);
	}

private:
	int rst_left, rst_len;

	int findPalindrome(string& s, int mid)
	{
		int left = mid, right = mid;
		while (right < s.length() && s[right] == s[right + 1])
			right++;
		int index = right;

		while (left > 0 && right < s.length() - 1 && s[left - 1] == s[right + 1])
		{
			left--;
			right++;
		}
		if (right - left + 1 > rst_len)
		{
			rst_left = left;
			rst_len = right - left + 1;
		}

		return index;
	}

	/*执行用时 :288 ms
	 *内存消耗 :15.7 MB*/
	/*string longestPalindrome(string s)
	{
		if (s.length() < 2) return s;
		string rst_str = s.substr(0, 1);
		int rst = 1;
		for (int i = 0; i < s.length() - rst; i++)
		{
			int end = s.find(s[i], i+1);
			while (end!= s.npos)
			{
				if (end - i >= rst)
				{
					if (isPalindrome(s, i, end))
					{
						rst_str = s.substr(i, end - i + 1);
						rst = end - i + 1;
					}
				}
				end = s.find(s[i], end + 1);
			}
		}
		return rst_str;
	}
	
private:

	bool isPalindrome(string& s, int l, int r)
	{
		while (l < r)
		{
			if (s[l] != s[r]) return false;
			l++;
			r--;
		}

		return true;
	}
	*/

	/*
	 * 执行用时 :380 ms
	内存消耗 :9.7 MB
	 */
	/*string longestPalindrome(string s)
	{
		bool dp[1001][1001];
		int len = s.length();
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++)
				if (i + 1 > j)
					dp[i][j] = true;
				else
					dp[i][j] = false;

		for (int l = 1; l < len; l ++)
		{
			for (int i = 0; i < len - l; i++)
			{
				if (s[i] == s[i + l])
					dp[i][i + l] = dp[i + 1][i + l - 1];
			}
		}

		for (int l = len; l >= 0; l--)
		{
			for (int i = 0; i < len - l; i++) { if (dp[i][i + l]) { return s.substr(i, l + 1); } }
		}
		return "";
	}*/
};

TEST(leecode, 5)
{
	string a = "d";
	Solution s;
	cout << s.longestPalindrome(a);
}
