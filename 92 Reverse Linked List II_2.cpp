// 92
// Reverse Linked List II
// https://leetcode.com//problems/reverse-linked-list-ii/
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == nullptr || m >= n) return head;
        if (m > 1) {
            head->next = reverseBetween(head->next, m - 1, n - 1);
            return head;
        }
        ListNode *head2, *p = head;
        for (; n > 0 && p; --n) {
            auto next = p->next;
            p->next = head2;
            head2 = p;
            p = next;
        }
        head->next = p;
        return head2;
    }
};