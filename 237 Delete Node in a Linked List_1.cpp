// 237
// Delete Node in a Linked List
// https://leetcode.com//problems/delete-node-in-a-linked-list/
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
    void deleteNode(ListNode* node) {
        if (node->next == nullptr) throw exception();
        auto tmp = node->next;
        *node = *tmp;
        delete tmp;
    }
};