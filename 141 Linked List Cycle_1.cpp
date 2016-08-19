// 141
// Linked List Cycle
// https://leetcode.com//problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode * p=head, *q=head->next;
        while(q&&q->next)
        {
            p=p->next;
            q=q->next;
            if(p==q) return true;
            q=q->next;
            if(p==q) return true;
        }
        return false;
    }
};