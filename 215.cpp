/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (58.64%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    50.9K
 * Total Submissions: 86.8K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> maxk;
        for (int i = 0; i < nums.size(); i++) {
            if (maxk.size() < k)
                maxk.insert(nums[i]);
            else if (nums[i] > *maxk.begin()) {
                maxk.erase(maxk.begin());
                maxk.insert(nums[i]);
            }
        }
        return *maxk.begin();
    }
};
// @lc code=end

