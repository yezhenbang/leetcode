/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (60.37%)
 * Likes:    337
 * Dislikes: 0
 * Total Accepted:    75.9K
 * Total Submissions: 125.9K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int rst;
        int rate = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (rate == 0) {
                rate = 1;
                rst = nums[i];
            }
            else {
                if (rst == nums[i])
                    rate++;
                else
                    rate--;
            }
        }

        return rst;
    }
};
// @lc code=end

