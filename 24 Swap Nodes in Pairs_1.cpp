// 24
// Swap Nodes in Pairs
// https://leetcode.com//problems/swap-nodes-in-pairs/
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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1), *prev = &dummy;
        dummy.next = head;
        for (ListNode *second, *third; head && head->next; prev = head, head = third) {
            second = head->next, third = second->next;
            second->next = head;
            head->next = third;
            prev->next = second;
        }
        return dummy.next;
    }
};