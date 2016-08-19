// 19
// Remove Nth Node From End of List
// https://leetcode.com//problems/remove-nth-node-from-end-of-list/
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1), *prev = &dummy, *q = head;
        dummy.next = head;
        int i = 0;
        for (; i < n && q; i++, q = q->next);
        if (i < n) return head;
        while (q) {
            q = q->next;
            prev = prev->next;
        }
        auto p = prev->next;
        prev->next = p->next;
        delete p;
        return dummy.next;
    }
};