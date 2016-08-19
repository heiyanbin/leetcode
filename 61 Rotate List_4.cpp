// 61
// Rotate List
// https://leetcode.com//problems/rotate-list/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !head->next||k<1) return head;
        ListNode* p=head, *q=head;
        int n=0;
        while(q && n<k)
        {
            q=q->next;
            n++;
        }
        if(q==NULL && n==k) 
            return head;
        else if(n<k)
        {
            k= k%n;
            for(n=0,q=head;n<k;n++)
                q=q->next;
        }
        while(q->next)
        {
            p=p->next;
            q=q->next;
        }
        q->next = head;
        head=p->next;
        p->next=NULL;
        return head;
    }
};