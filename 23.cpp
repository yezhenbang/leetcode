#include "pch.h"
#include "heap.h"

/*  ##description
	合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

普通扫描：O(n*合并后总长度)
heap： O(logn*合并后总长度)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution23 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* head = new ListNode(-1);
		ListNode* tail = head;

		Heap<ListNode*> heap([](const ListNode* a, const ListNode* b) {return a->val < b->val; });
		try
		{
			for (const auto& list : lists)
				if (list)
					heap.insert(list);

			while (true)
			{
				ListNode* tmp = heap.pop();
				if (tmp == nullptr)
					continue;
				tail->next = tmp;
				tail = tmp;
				if (tmp->next != nullptr)
					heap.insert(tmp->next);
			}
		}
		catch (std::invalid_argument& e)
		{
		}

		tail = head->next;
		delete head;
		return tail;
	}
};

TEST(leetcode, 23)
{
	vector<ListNode*> lists;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(5);
	head->next->next->next = new ListNode(8);
	lists.push_back(head);

	head = new ListNode(1);
	head->next = new ListNode(3);
	head->next->next = new ListNode(4);
	lists.push_back(head);

	head = nullptr;
	lists.push_back(head);

	head = new ListNode(2);
	head->next = new ListNode(6);
	head->next->next = new ListNode(7);
	lists.push_back(head);

	head = nullptr;
	lists.push_back(head);

	Solution23 s;
	head = s.mergeKLists(lists);
	showAndDeleteList(head);
}
