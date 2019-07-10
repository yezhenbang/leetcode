#include "pch.h"

/*  ##description
	将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.*/

 
class Solution21 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = NULL;
		ListNode** tmp = &head;
		while (l1 != NULL || l2 != NULL)
		{
			if (l1 == NULL)
			{
				*tmp = l2;
				tmp = &l2->next;
				l2 = l2->next;
				continue;
			}
			if (l2 == NULL || l1->val <= l2->val)
			{
				*tmp = l1;
				tmp = &l1->next;
				l1 = l1->next;
				continue;
			}

			*tmp = l2;
			tmp = &l2->next;
			l2 = l2->next;
			continue;
		}
		return head;
	}
};

TEST(leetcode, 21)
{
	ListNode* head = new ListNode(1);
	// head->next = new ListNode(2);
	// head->next->next = new ListNode(3);
	// head->next->next->next = new ListNode(4);
	// head = NULL;

	ListNode* head2 = new ListNode(3);
	// head2->next = new ListNode(5);
	// head2->next->next = new ListNode(6);
	// head2->next->next->next = new ListNode(7);
	head2 = NULL;
	Solution21 s;
	ListNode* new_head = s.mergeTwoLists(head, head2);
	showAndDeleteList(new_head);
}
