// 2
// Add Two Numbers
// https://leetcode.com//problems/add-two-numbers/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *p=&dummy;
        int carry =0;
        for(;l1 && l2; p=p->next,l1=l1->next,l2=l2->next)
        {
            int sum = l1->val+l2->val+ carry;
            p->next = new ListNode(sum%10);
            carry = sum/10;
        }
        for(;l1; p=p->next,l1=l1->next)
        {
           int sum=l1->val+carry;
           p->next = new ListNode(sum%10);
           carry = sum/10;
        }
        for(;l2;p=p->next,l2=l2->next)
        {
           int sum=l2->val+carry;
           p->next = new ListNode(sum%10);
           carry = sum/10;
        }
        if(carry>0)
            p->next = new ListNode(carry);
        return dummy.next;
    }
};