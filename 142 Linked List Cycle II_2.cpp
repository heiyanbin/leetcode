// 142
// Linked List Cycle II
// https://leetcode.com//problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        auto p = head, q = head;
        while (q && q->next) {
            q = q->next->next;
            p = p->next;
            if (p == q) break;
        }
        if (p != q) return nullptr;
        for (p = head; p != q; p = p->next, q = q->next) ;
        return p;
    }
};