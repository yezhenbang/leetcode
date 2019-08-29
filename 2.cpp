#include "pch.h"

/**
 *
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * Definition for singly-linked list.
 */
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int sub = l1->val + l2->val;
		ListNode* rst_root = new ListNode(sub % 10);
		ListNode* current = rst_root;
		sub /= 10;

		while (l1->next || l2->next || sub > 0)
		{
			if (l1->next)
			{
				l1 = l1->next;
				sub += l1->val;
			}
			if (l2->next)
			{
				l2 = l2->next;
				sub += l2->val;
			}
			current->next = new ListNode(sub % 10);
			current = current->next;
			sub = sub / 10;
		}

		return rst_root;
	}
};

void delete_list(ListNode* i)
{
	while (i != NULL)
	{
		auto tmp = i;
		i = i->next;
		delete tmp;
	}
}

TEST(leetcode, 2)
{
	ListNode* a = new ListNode(0);
	ListNode* b = new ListNode(0);
	// b->next = new ListNode(9);
	// b->next->next = new ListNode(9);
	// b->next->next->next = new ListNode(9);

	Solution s;
	auto rst = s.addTwoNumbers(a, b);
	auto tmp = rst;
	while (tmp)
	{
		cout << tmp->val;
		tmp = tmp->next;
	}

	delete_list(a);
	delete_list(b);
	delete_list(rst);
}