// 21
// Merge Two Sorted Lists
// https://leetcode.com//problems/merge-two-sorted-lists/
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1), *prev;
        for (prev = &dummy; l1 && l2; prev = prev -> next) {
            if (l1 -> val <= l2 -> val) {
                prev -> next = l1;
                l1 = l1 -> next;
            }
            else {
                prev -> next = l2;
                l2 = l2 -> next;
            }
        }
        prev -> next = l1 ? l1 : l2;
        return dummy.next;
    }
};