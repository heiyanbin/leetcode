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
        auto p = &dummy;
        for(int carry = 0; l1||l2||carry; l1 = l1 ? l1->next :NULL, l2 = l2 ? l2->next :NULL, p=p->next)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            p->next = new ListNode(sum % 10);
            carry = sum / 10;
        }
        return dummy.next;
    }
};