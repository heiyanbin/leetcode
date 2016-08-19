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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(-1), *prev= &dummy;
        dummy.next = head;
        for (auto start = head; start; ) {
            int i = 0;
            auto end = start;
            for(; end && i < k; end = end->next, i++) ;
            if (i < k) break; //last group less than k, don't reverse and all groups done

            for (auto cur = start; cur != end; ) {
                auto next = cur->next; 
                cur->next=prev->next; //use left outer node's next field as the head2 variable
                prev->next = cur;
                cur = next;
            }
            start->next = end;
            prev = start;
            start = end;
        }
        return dummy.next;
    }
};