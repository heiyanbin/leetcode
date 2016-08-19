// 148
// Sort List
// https://leetcode.com//problems/sort-list/
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
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *p = head, *preP=NULL, *q= head;
        while(q && q->next)
        {
            preP=p;
            p=p->next;
            q=q->next->next;
        }
        preP->next = NULL;
        return merge(sortList(head), sortList(p));
    }
    ListNode* merge(ListNode* a, ListNode* b)
    {
        if(!a) return b;
        if(!b) return a;
        ListNode* head;
        if(a->val<=b->val)
        {
            head=a;
            head->next = merge(a->next,b);
        }
        else
        {
            head=b;
            head->next = merge(a,b->next);
        }
        return head;
    }
};