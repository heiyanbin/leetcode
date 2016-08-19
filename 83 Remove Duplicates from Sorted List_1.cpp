// 83
// Remove Duplicates from Sorted List
// https://leetcode.com//problems/remove-duplicates-from-sorted-list/
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
    ListNode *deleteDuplicates(ListNode *head) {
        for (auto cur = head; cur; ) {
            while (cur->next && cur->next->val == cur->val) {
                auto tmp = cur->next->next;
                delete cur->next;
                cur->next = tmp;
            }
            cur = cur->next;
        }
        return head;
    }
};