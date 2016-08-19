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
        if(!head) return NULL;
        ListNode *p = head, *q=head;
        while(q && n>0)
        {
            q=q->next;
            n--;
        }
        if(n>0) return head;
        
        ListNode* prev= NULL;
        while(q)
        {
            q=q->next;
            prev=p;
            p=p->next;
        }
        ListNode * next = p->next;
        delete p;
        if(prev)
            prev->next = next;
        else
            head=next;
            
        return head;
            
    }
};