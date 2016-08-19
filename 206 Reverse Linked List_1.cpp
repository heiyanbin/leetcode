// 206
// Reverse Linked List
// https://leetcode.com//problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        ListNode* head2 = nullptr;
        for (auto p = head; p;) {
            auto next = p -> next;
            p -> next = head2;
            head2 = p;
            p = next;
        }
        return head2;
    }
};