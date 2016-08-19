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
        ListNode dummy(-1);
        dummy.next = head;
        auto q = head;
        int i = 0;
        for (; q && i < n; q = q->next, ++i) ;
        if (i < n) return head;
        auto p = &dummy;
        for (; q; p = p->next, q = q->next) ;
        auto tmp = p->next;
        p->next = tmp->next;
        delete tmp;
        return dummy.next;
    }
};