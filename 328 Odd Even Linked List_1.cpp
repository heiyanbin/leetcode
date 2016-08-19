// 328
// Odd Even Linked List
// https://leetcode.com//problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddDummy(-1), evenDummy(-1);
        ListNode *oddTail = &oddDummy, *evenTail = &evenDummy, *cur = head;
        for (int i = 1; cur; ++i, cur = cur->next) {
            if (i & 1) {
                oddTail->next = cur;
                oddTail = cur;
            }
            else {
                evenTail->next = cur;
                evenTail = cur;
            }
        }
        oddTail->next = evenDummy.next;
        evenTail->next = nullptr;
        return oddDummy.next;
    }
};