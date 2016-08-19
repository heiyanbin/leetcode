// 61
// Rotate List
// https://leetcode.com//problems/rotate-list/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !head->next||k<1) return head;
        ListNode* p=head, *q=head, *prev=NULL;
        int n=0;
        while(q && n<k)
        {
            prev=q;
            q=q->next;
            n++;
        }
        if(!q && n==k) 
            return head;
        else if(n<k)
            k= k%n;
        else
        {
            while(q)
            {
                prev=q;
                q=q->next;
                n++;
            }
        }
        int i=0;
        while(i<n-(k+1))
        {
            p=p->next;
            i++;
        }
        prev->next = head;
        head=p->next;
        p->next=NULL;
        return head;
    }
};