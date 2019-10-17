/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 *
 * https://leetcode-cn.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (38.23%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    2.8K
 * Total Submissions: 7.2K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * 给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。
 * 
 * 注意:
 * 数组长度 n 满足以下条件:
 * 
 * 
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 * 
 * 
 * 示例: 
 * 
 * 
 * 输入:
 * nums = [7,2,5,10,8]
 * m = 2
 * 
 * 输出:
 * 18
 * 
 * 解释:
 * 一共有四种方法将nums分割为2个子数组。
 * 其中最好的方式是将其分为[7,2,5] 和 [10,8]，
 * 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<unsigned int> sum(n);
        sum[0] = nums[0];
        for (int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + nums[i];
        vector<unsigned int> dp(sum);
        for (int k = 1; k < m; k++) {
            for (int i = n - 1; i >= k; i--) {
                for (int j = k; j <= i; j++) {
                    dp[i] = min(dp[i], max(dp[j - 1], sum[i] - sum[j - 1]));
                }
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

