// 86
// Partition List
// https://leetcode.com//problems/partition-list/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head||!head->next) return head;
        ListNode *p = head, *q =head;
        while(q->next)
            q=q->next;
        ListNode * end= q, *prev = NULL;
        while(p!=q)
        {
            if(p->val< x)
            {
                prev=p;
                p=p->next;
            }
            
            else
            {
                ListNode * next = p->next;
                end->next = p;
                p->next = NULL;
                end = p;
                if(p!=head)
                {
                    prev->next = next;
                }
                else
                {
                    head = next;
                    prev = head;
                }
                p=next;
            }
        }
        if(p->val >= x && end!=p)
        {
            ListNode * next = p->next;
            end->next = p;
            p->next = NULL;
            
            if(p!=head)
            {
                prev->next = next;
            }
            else
            {
                head = next;
            }
        }
        return head;
        
    }
};