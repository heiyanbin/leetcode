// 82
// Remove Duplicates from Sorted List II
// https://leetcode.com//problems/remove-duplicates-from-sorted-list-ii/
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
        ListNode dummy(-1), *prev= &dummy;
        dummy.next = head;
        while (head) {
            bool delHead = false;
            while (head->next && head->next->val == head->val) {
                auto tmp = head->next->next;
                delete head->next;
                head->next = tmp;
                delHead = true;
            }
            if (!delHead) {
                prev = head;
                head = head->next;
            }
            else {
                auto tmp = head->next;
                delete head;
                head = tmp;
                prev->next = head;
            }
        }
        return dummy.next;
    }
};