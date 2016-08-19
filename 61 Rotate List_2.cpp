// 61
// Rotate List
// https://leetcode.com//problems/rotate-list/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || k<1) return head;
        auto q=head;
        int len =1;
        for(;q->next;q=q->next)
            len++;
        k=len-k%len;
        q->next = head;
        for(int i=0;i<k;i++)
            q=q->next;
        head=q->next;
        q->next=NULL;
        return head;
    }
};