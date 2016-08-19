// 24
// Swap Nodes in Pairs
// https://leetcode.com//problems/swap-nodes-in-pairs/
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
    ListNode *swapPairs(ListNode *head) {
        if(!head ||!head->next) 
            return head;
        
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode*p = fakeHead, *q=head;
        int i=1;
        while(q->next)
        {
            if(i&1==1)
            {
                ListNode* next= q->next->next;
                p->next =q->next;
                p->next->next=q;
                q->next= next;
                p=p->next;
            }
            else
            {
                p=q;
                q=q->next;
            }
            i++;
        }
        return fakeHead->next;
    }
};