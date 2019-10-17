/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (40.90%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 10.7K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s = "aaabb", k = 3
 * 
 * 输出:
 * 3
 * 
 * 最长子串为 "aaa" ，其中 'a' 重复了 3 次。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s = "ababbc", k = 2
 * 
 * 输出:
 * 5
 * 
 * 最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
 * 
 * 
 */
#include "pch.h"
// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        rst = 0;
        check(s, 0, s.length() - 1, k);
        return rst;
    }
private:
    void check(string& s, int l, int r, int k) {
        if (l > r || rst > r - l)
            return;
        vector<int> times(26, 0);
        for (int i = l; i <= r; i++)
            times[s[i] - 'a']++;
        
        int left = l;
        for (int i = l; i <= r; i++){
            if (times[s[i] - 'a'] > 0 && times[s[i] - 'a'] < k) {
                check(s, left, i - 1, k);
                left = i + 1;
            }
        }
        if (left == l)
            rst = max(rst, r - l + 1);
        else 
            check(s, left, r, k);
    }

    int rst;
};
// @lc code=end
TEST(leetcode, testing_395)
{
	Solution s;
	cout << s.longestSubstring("a", 2);
}

