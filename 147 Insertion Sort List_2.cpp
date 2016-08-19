// 147
// Insertion Sort List
// https://leetcode.com//problems/insertion-sort-list/
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
    ListNode *insertionSortList(ListNode *head) {
        if(!head||!head->next) return head;
        ListNode dummy(-1);
        dummy.next=head;
        for(ListNode* p= head; p->next; )
        {
            bool inserted =false;
            for(ListNode* q= &dummy; q!=p;q=q->next)
            {
                if(p->next->val< q->next->val)
                {
                    ListNode* tmp =p->next;
                    p->next=tmp->next;
                    tmp->next=q->next;
                    q->next=tmp;
                    inserted= true;
                    break;
                }
            }
            if(!inserted)
                p=p->next;
        }
        return dummy.next;
    }
};