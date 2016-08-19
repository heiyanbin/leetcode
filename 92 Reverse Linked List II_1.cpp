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
        ListNode dummy(-1), *prevM = &dummy;
        dummy.next = head;
        for (int i = 0; i < m - 1 && prevM->next; ++i, prevM = prevM->next) ;
        if (!prevM->next) return head;
        auto &head2 = prevM->next, cur = prevM->next, start = prevM->next;
        for (int i = m; i <= n && cur; ++i) {
            auto next = cur->next;
            cur->next = head2;
            head2 = cur;
            cur = next;
        }
        start->next = cur;
        return dummy.next;
    }
};