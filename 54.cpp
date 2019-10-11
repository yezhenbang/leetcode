/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (37.23%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    26.4K
 * Total Submissions: 70.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        rst.clear();
        if (matrix.empty() || matrix[0].empty())
            return rst;
        row_b = 0;
        row_e = matrix.size() - 1;
        col_b = 0;
        col_e = matrix[0].size() - 1;
        traverRow(matrix, row_b, 1);

        return rst;
    }

private:

    void traverRow(vector<vector<int>>& matrix, int traRow, int direction) {
        if (col_b > col_e) 
            return;
        int begin = direction == 1? col_b : col_e;
        int end = direction == 1? col_e : col_b;

        for (; begin != end + direction; begin += direction)
            rst.push_back(matrix[traRow][begin]);
        if (traRow == row_b) {
            row_b++;
            traverCol(matrix, col_e, 1);
        }
        else {
            row_e--;
            traverCol(matrix, col_b, -1);
        }
    }
    void traverCol(vector<vector<int>>& matrix, int traCol, int direction) {
        if (row_b > row_e)
            return;
        int begin = direction == 1? row_b : row_e;
        int end = direction == 1? row_e : row_b;

        for (; begin != end + direction; begin += direction)
            rst.push_back(matrix[begin][traCol]);
        if (traCol == col_b) {
            col_b++;
            traverRow(matrix, row_b, 1);
        }
        else {
            col_e--;
            traverRow(matrix, row_e, -1);
        }
    }

    int row_b, row_e;
    int col_b, col_e;
    vector<int> rst;
};
// @lc code=end

