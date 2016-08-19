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
        if(!l1) return l2;
        if(!l2) return l1;
        
        int sum = l1->val+l2->val;
        ListNode *head = new ListNode(sum%10);
        int carry =sum/10;
        ListNode *p = head;
        l1=l1->next;
        l2=l2->next;
        while(l1&&l2)
        {
            sum = l1->val+l2->val+ carry;
            p->next = new ListNode(sum%10);
            carry = sum/10;
            p=p->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
           sum=l1->val+carry;
           p->next = new ListNode(sum%10);
           carry = sum/10;
           p=p->next;
           l1=l1->next;
        }
        while(l2)
        {
           sum=l2->val+carry;
           p->next = new ListNode(sum%10);
           carry = sum/10;
           p=p->next;
           l2=l2->next;
        }
        if(carry!=0)
            p->next = new ListNode(carry);
        return head;
    }
};