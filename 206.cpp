/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (64.84%)
 * Likes:    602
 * Dislikes: 0
 * Total Accepted:    107K
 * Total Submissions: 164.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* tmp = head->next;
        head->next = NULL;
        return cursionSwap(tmp, head);
    }

private:
    ListNode* cursionSwap(ListNode* current, ListNode* head) {
        if (current == NULL)
            return head;
        ListNode* tmp = current->next;
        current->next = head;
        return cursionSwap(tmp, current);
    }
};
// @lc code=end

