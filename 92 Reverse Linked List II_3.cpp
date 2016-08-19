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
        if (!head || !head ->next || m < 1 || n < 1 || n <= m) return head;
        if (m > 1) {
            auto x = reverseBetween(head -> next, m - 1, n - 1);
            if (x != nullptr)  head -> next = x;
            return head;
        } else {
            auto end = head;
            int i = 0;
            for (; i < n && end; i++)
                end = end -> next;
            if (i < n) return nullptr;
            auto head2 = end;
            for (auto p = head; p != end; ) {
                auto next = p -> next;
                p -> next = head2;
                head2 = p;
                p = next;
            }
            return head2;
        }
    }
};