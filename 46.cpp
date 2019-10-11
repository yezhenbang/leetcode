/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (72.14%)
 * Likes:    409
 * Dislikes: 0
 * Total Accepted:    50.5K
 * Total Submissions: 70K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            rst.push_back(vector<int>());
            return rst;
        }

        visited.resize(nums.size());
        for (int i = 0; i < nums.size(); i++)
            visited[i] = false;
            
        vector<int> solution;
        for (int i = 0; i < nums.size(); i++) {
            solution.push_back(nums[i]);
            visited[i] = true;
            traver(nums, solution); 
            solution.pop_back();
            visited[i] = false;
        }

        return rst;
    }

private:

    void traver(vector<int>& nums, vector<int>& solution) {
        if (solution.size() == nums.size()) {
            rst.push_back(solution);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;

            solution.push_back(nums[i]);
            visited[i] = true;
            traver(nums, solution); 
            solution.pop_back();
            visited[i] = false;
        }
    }

    vector<bool> visited;
    vector<vector<int>> rst;
};
// @lc code=end

