// 160
// Intersection of Two Linked Lists
// https://leetcode.com//problems/intersection-of-two-linked-lists/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL) return NULL;
        int a = 1, b=1;
        auto p= headA, q= headB;
        for(;p->next;a++,p=p->next);
        for(;q->next;b++,q=q->next);
        if(p!=q) return NULL;
        p = a> b? headA: headB;
        q = p==headA ? headB : headA;
        for(int diff= abs(a-b);diff>0;p=p->next,diff--);
        for(;p!=q;p=p->next,q=q->next);
        return p;
    }
};