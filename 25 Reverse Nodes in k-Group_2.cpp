// 25
// Reverse Nodes in k-Group
// https://leetcode.com//problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 0;
        auto p = head;
        for (; i < k && p; ++i, p = p -> next);
        if (i < k) return head;
        ListNode* head2 = nullptr;
        for (auto q = head; q != p;) {
            auto next = q -> next;
            q -> next = head2;
            head2 = q;
            q = next;
        }
        head -> next = reverseKGroup(p, k);
        return head2;
    }
};