// 234
// Palindrome Linked List
// https://leetcode.com//problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        int n = 0;
        for (auto cur = head; cur; ++n, cur = cur->next);
        
        auto p = head, q = head;
        while (q && q->next) {
            q = q->next->next;
            p = p->next;
        }
        auto reverse = [](ListNode* head, ListNode* end) {
            ListNode* head2 = nullptr;
            for (auto p = head; p != end;) {
                auto next = p->next;
                p->next = head2;
                head2 = p;
                p = next;
            } 
            return head2;
        };
       
        auto head2 = reverse(head, p);
        if (n & 1) p = p->next;
        for(; p && head2; p = p->next, head2= head2->next) {
            if (p->val != head2->val) return false;
        }
        return true;
    }
    
    
};