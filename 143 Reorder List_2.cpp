// 143
// Reorder List
// https://leetcode.com//problems/reorder-list/
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
    void reorderList(ListNode *head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode *p=head, *q=head;
        while(q && q->next)
        {
            p=p->next;
            q=q->next->next;
        }
        ListNode *head2 = p->next;
        p->next=NULL;
        
        head2=reverse(head2);
        while(head2)
        {
            ListNode *next= head->next;
            head->next=head2;
            head2=head2->next;
            head->next->next=next;
            head = next;
        }
    }
    ListNode* reverse(ListNode *head)
    {
        if(!head || !head->next) 
            return head;
        ListNode* head2= head;
        head=head->next;
        head2->next=NULL;
        while(head)
        {
            ListNode *next= head->next;
            head->next=head2;
            head2=head;
            head=next;
        }
        return head2;
    }
    
    
};