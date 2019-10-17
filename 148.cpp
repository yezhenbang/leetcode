/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (62.24%)
 * Likes:    302
 * Dislikes: 0
 * Total Accepted:    26.5K
 * Total Submissions: 42.6K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
private:
    ListNode* mergeSort(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* head2 = divide(head);
        return merge(mergeSort(head), mergeSort(head2));
    }

    ListNode* divide(ListNode* head) {
        ListNode* mid = head;
        ListNode* tmp = head->next;
        while (tmp != NULL && tmp->next != NULL) {
            tmp = tmp->next->next;
            mid = mid->next;
        }
        
        tmp = mid->next;
        mid->next = NULL;
        return tmp;
    }

    ListNode* merge(ListNode* h1, ListNode* h2) {
        if (h1 == NULL) return h2;
        if (h2 == NULL) return h1;
        
        ListNode* head = NULL;
        if (h1->val < h2->val) {
            head = h1;
            h1 = h1->next;
        }
        else {
            head = h2;
            h2 = h2->next;
        }
        ListNode* tail = head;

        while (h1 != NULL && h2 != NULL) {
            if (h1->val < h2->val) {
                tail->next = h1;
                h1 = h1->next;
            } 
            else {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }

        if (h1 == NULL) 
            h1 = h2;
        while (h1 != NULL) {
            tail->next = h1;
            tail = h1;
            h1 = h1->next;
        }
        return head;
    }
};
// @lc code=end

