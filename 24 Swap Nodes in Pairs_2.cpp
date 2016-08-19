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
        if (!head || !head->next) return head;
        auto second = head->next, right_outer = second->next;
        second->next = head;
        head->next = swapPairs(right_outer);
        return second;
    }
};