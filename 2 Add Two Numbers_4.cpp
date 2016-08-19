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
        return add(l1,l2,0);
    }
    ListNode * add(ListNode* l1, ListNode* l2, int carry)
    {
        if(!l1 && !carry) return l2;
        if(!l2 && !carry) return l1;
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        ListNode *head = new ListNode(sum % 10);
        head->next = add(l1 ? l1->next : NULL, l2 ? l2->next : NULL, sum/10);
        return head;
    }
};