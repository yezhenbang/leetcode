#include "pch.h"

/*  ##description
	给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


 // Definition for singly-linked list.
class Solution19 {
public:
	// 还可以使用双指针
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head)
			return head;
		return findLastNAndDelete(head, n);
	}

private:
	ListNode* findLastNAndDelete(ListNode* node, int& n)
	{
		if (node->next != NULL)
			node->next = findLastNAndDelete(node->next, n);
		n--;
		if (n == 0)
		{
			ListNode* tmp = node->next;
			delete node;
			return tmp;
		}
		return node;
	}
};

TEST(leetcode, 19)
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	// head->next->next = new ListNode(3);
	// head->next->next->next = new ListNode(4);
	// head->next->next->next->next = new ListNode(5);
	// head->next->next->next->next->next = new ListNode(6);
	Solution19 s;

	head = s.removeNthFromEnd(head, 2);
	auto i = head;
	while (i)
	{
		cout << i->val << " ";
		auto tmp = i;
		i = i->next;
		delete tmp;
	}
}
