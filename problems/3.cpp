#include "pch.h"
#include <queue>
/*
 *给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 

*/

/*执行用时 :16 ms
内存消耗 :9.2 MB*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ch_appear_record[256] = { 0 };
		int start = 0, max_len = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (ch_appear_record[(int)s[i]] != 0)
			{
				start = max(start, ch_appear_record[(int)s[i]]);
			}
			ch_appear_record[(int)s[i]] = i + 1;
			max_len = max(i - start + 1, max_len);
		}
		return max_len;
	}
};


/*
执行用时 :28 ms
内存消耗 :10.7 MB
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> ch_appear_record;
		int len = 0, max_len = 0;
		for (int i = 0; i < s.length(); i++)
		{
			auto p = ch_appear_record.find(s[i]);
			if (p != ch_appear_record.end())
			{
				len = min(len, (i - p->second - 1));
				p->second = i;
			}
			else
			{
				ch_appear_record[s[i]] = i;
			}
			len++;
			max_len = max(len, max_len);
		}
		return max_len;
    }
};
*/

TEST(leetcode, 3)
{
	string a = "abcabcbb";
	Solution s;
	cout << s.lengthOfLongestSubstring(a);
}