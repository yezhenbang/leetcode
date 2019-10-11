#include "pch.h"
/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (37.88%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    15.4K
 * Total Submissions: 40.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        rst = root->val;
		recurse(root);
        return rst;
    }
private:
    int recurse(TreeNode* node){
        if (node == NULL) return 0;

        int nLeftMax = recurse(node->left);
        int nRightMax = recurse(node->right);
        int nCurrentMax = node->val + max(nLeftMax, 0) + max(nRightMax, 0);
        if (nCurrentMax > rst)
        rst = nCurrentMax;

        return node->val + max(0, max(nLeftMax, nRightMax));
    }

    void traver(TreeNode* node) {
		if (node == NULL) return;

		int currentMax = node->val;
		if (arriveAt(node->left) > 0)
			currentMax += arriveAt(node->left);
		if (arriveAt(node->right) > 0)
			currentMax += arriveAt(node->right);

		if (currentMax > rst)
			rst = currentMax;

		traver(node->left);
		traver(node->right);
    }
    int arriveAt(TreeNode* node) {
		if (node == NULL) return 0;
		static map<TreeNode*, int> arriveAtRecord;
		{
			auto p = arriveAtRecord.find(node);
			if (p != arriveAtRecord.end())
				return p->second;
		}

		int nArriveMax = node->val;
		int nArriveLeft = arriveAt(node->left);
		int nArriveRight = arriveAt(node->right);
		nArriveMax += max(0, max(nArriveLeft, nArriveRight));
		arriveAtRecord[node] = nArriveMax;
		return nArriveMax;
    }

    int rst;
};
// @lc code=end

