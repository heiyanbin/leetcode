// 92
// Reverse Linked List II
// https://leetcode.com//problems/reverse-linked-list-ii/
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head || m==n) return head;
        ListNode dummy(-1);
        dummy.next=head;
        int nodeNum =0;
        ListNode* p = &dummy;
        
        while(p && nodeNum < m-1)
        {
            p=p->next;
            nodeNum++;
        }
        if(!p||!(p->next)) return head;
        ListNode * const head2 = p;
        p=p->next;
        nodeNum++;
        ListNode *cur=p->next;
        while(cur && nodeNum<n)
        {
            p->next = cur->next;
            cur->next = head2->next;
            head2->next=cur;
            cur=p->next;
            nodeNum++;
        }
        return dummy.next;
    }
};