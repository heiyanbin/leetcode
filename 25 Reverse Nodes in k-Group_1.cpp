// 25
// Reverse Nodes in k-Group
// https://leetcode.com//problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1), *prev = &dummy;
        dummy.next = head;
        for (ListNode *q, *p; head; prev = head, head = q) {
            int i = 0;
            for (q = head; i < k && q; ++i) q = q->next;
            if (i < k) break;
            for (p = head, prev->next = q; p != q; ) { 
                auto next = p->next;
                p->next = prev->next;//prev->next as the head2 variable
                prev->next = p;
                p = next;
            }
        }
        return dummy.next;
    }
};