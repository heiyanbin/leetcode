// 61
// Rotate List
// https://leetcode.com//problems/rotate-list/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || k<1) return head;
        auto p = head, q=head;
        int len =1;
        for(;q->next;q=q->next)
            len++;
        k=k%len;
        if(k==0) return head;
        for(int i=0;i<len-k-1;i++)
            p=p->next;
        auto head2= p->next;
        p->next = NULL;
        q->next = head;
        return head2;
    }
};