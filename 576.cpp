/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 *
 * https://leetcode-cn.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (33.67%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 4.2K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * 给定一个 m × n 的网格和一个球。球的起始坐标为 (i,j)
 * ，你可以将球移到相邻的单元格内，或者往上、下、左、右四个方向上移动使球穿过网格边界。但是，你最多可以移动 N
 * 次。找出可以将球移出边界的路径数量。答案可能非常大，返回 结果 mod 10^9 + 7 的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: m = 2, n = 2, N = 2, i = 0, j = 0
 * 输出: 6
 * 解释:
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入: m = 1, n = 3, N = 3, i = 0, j = 1
 * 输出: 12
 * 解释:
 * 
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 球一旦出界，就不能再被移动回网格内。
 * 网格的长度和高度在 [1,50] 的范围内。
 * N 在 [0,50] 的范围内。
 * 
 */

// @lc code=start
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0)
            return 0;
        const int precision = pow(10, 9) + 7;
        unsigned int dp[2][52][52];
        unsigned int rst = 0;
        for (int i = 0; i < 52; i++)
            for (int j = 0; j < 52; j++) {
                dp[0][i][j] = 0;
                dp[1][i][j] = 0;
            }

        dp[0][i + 1][j + 1] = 1;
        if (i == 0) rst++;
        if (i == m - 1) rst++;
        if (j == 0) rst++;
        if (j == n - 1) rst++;

        for (int i = 1; i < N; i++) {
            int cur = i % 2;
            int pre = (i + 1) % 2;
            for (int row = 1; row <= m; row++)
                for (int col = 1; col <= n; col++) {
                    dp[cur][row][col] = dp[pre][row - 1][col] + dp[pre][row + 1][col] + dp[pre][row][col - 1] + dp[pre][row][col + 1];
                    dp[cur][row][col] %= precision;
                    if (row == 1)
                        rst = (rst + dp[cur][row][col]) % precision;
                    if (row == m)
                        rst = (rst + dp[cur][row][col]) % precision;
                    if (col == 1)
                        rst = (rst + dp[cur][row][col]) % precision;
                    if (col == n)
                        rst = (rst + dp[cur][row][col]) % precision;
                }
        }
        return rst;
    }
};
// @lc code=end

