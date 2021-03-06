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
        ListNode *p=head, *q=head;
        while(q && q->next)
        {
            p=p->next;
            q=q->next->next;
            if(p==q)
            {
                ListNode *r= head;
                while(p!=r)
                {
                    p=p->next;
                    r=r->next;
                }
                return r;
            }
        }
        return NULL;
    }
};