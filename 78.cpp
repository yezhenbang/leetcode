/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (74.99%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    39.8K
 * Total Submissions: 53.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rst;
        vector<int> solution;
        traver(rst, nums, solution, 0);
        return rst;
    }

private:
    void traver(vector<vector<int>>& rst, vector<int>& nums, vector<int>& solution, int k) {
        if (k == nums.size()) {
            rst.push_back(solution);
            return;
        }

        traver(rst, nums, solution, k + 1);
        solution.push_back(nums[k]);
        traver(rst, nums, solution, k + 1);
        solution.pop_back();
    }
};
// @lc code=end

