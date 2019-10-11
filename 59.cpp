/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (75.12%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    17.2K
 * Total Submissions: 22.9K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> rst;
        rst.resize(n);
        for (int i = 0; i < n; i++)
            rst[i].resize(n);
        
        row_b = 0;
        row_e = n - 1;
        col_b = 0; 
        col_e = n - 1;
        k = n * n;
        traverRow(rst, 0, 1, 0);
        return rst;
    }

private:

    void traverRow(vector<vector<int>>& matrix, int traRow, int direction, int i) {
        if (col_b > col_e) 
            return;
        int begin = direction == 1? col_b : col_e;
        int end = direction == 1? col_e : col_b;

        for (; begin != end + direction; begin += direction)
            matrix[traRow][begin] = ++i;
        if (traRow == row_b) {
            row_b++;
            traverCol(matrix, col_e, 1, i);
        }
        else {
            row_e--;
            traverCol(matrix, col_b, -1, i);
        }
    }
    void traverCol(vector<vector<int>>& matrix, int traCol, int direction, int i) {
        if (row_b > row_e)
            return;
        int begin = direction == 1? row_b : row_e;
        int end = direction == 1? row_e : row_b;

        for (; begin != end + direction; begin += direction)
            matrix[begin][traCol] = ++i;
        if (traCol == col_b) {
            col_b++;
            traverRow(matrix, row_b, 1, i);
        }
        else {
            col_e--;
            traverRow(matrix, row_e, -1, i);
        }
    }

    int row_b, row_e;
    int col_b, col_e;
    int k;
};
// @lc code=end

