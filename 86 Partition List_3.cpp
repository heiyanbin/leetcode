// 86
// Partition List
// https://leetcode.com//problems/partition-list/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head||!head->next) return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *p = head, *q =head;
        while(q->next)
            q=q->next;
        ListNode * end= q, *prev = &dummy;
        while(true)
        {
            auto next = p->next;
            if(p->val< x)
                prev=p;
            else if(end!=p)
            {
                end->next = p;
                p->next = NULL;
                end = p;
                prev->next = next;
            }
            if(p==q)
                break;
            p=next;
        }
        return dummy.next;
    }
};