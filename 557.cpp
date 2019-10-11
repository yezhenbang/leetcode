/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (67.97%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    30K
 * Total Submissions: 44.1K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
            return s;
        size_t pos_space = -1;
        size_t l, r;
        do {
            l = pos_space + 1;
            pos_space = s.find(' ', pos_space + 1);
            r = pos_space == string::npos? s.length() - 1 : pos_space - 1;

            while (l < r)
            {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        } while (pos_space != string::npos);

        return s;
    }
};
// @lc code=end

