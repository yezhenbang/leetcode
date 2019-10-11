#include "pch.h"
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (54.64%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    23.3K
 * Total Submissions: 42.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 示例 :
 * 
 * 给定这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 说明 :
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* rst = new ListNode(0);
        rst->next = head;
        ListNode* l = rst;
        ListNode* r = head;
        int i = 0;
        while (r != NULL) {
            i++;
			r = r->next;
			if (i >= k)
            {
				ListNode* tmp = l->next;
				l->next = reverseK(l->next, r, k);
				l = tmp;
                i = 0;
            }
		}

        return rst->next;
    }

private:
    ListNode* reverseK(ListNode* head, ListNode* nextK, int k)
    {
        if (k <= 1)
        {
            head->next = nextK;
            return head;
        }
        ListNode* tmp = head->next;
        head->next = nextK;
        return reverseK(tmp, head, k - 1);
    }
};
// @lc code=end

TEST(leetcode, 25)
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	Solution s;
	head = s.reverseKGroup(head, 4);
	showAndDeleteList(head);
}