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
        if(!head || m==n || m<1 || n< 1) return head;
        ListNode dummy(-1), *prev= &dummy;
        dummy.next=head;
        for(int i= 0; i < m-1 && prev; i++)
            prev=prev->next;
        if(!prev||!prev->next||!prev->next->next) //less than m-1 or just m-1 or just m nodes, nothing to do.
            return head;
        ListNode* const mthNode = prev->next, *cur=mthNode->next;
        for(int i=m+1; i<=n && cur; i++)
        {
            mthNode->next = cur->next; //m node's next field as the next variable 
            cur->next = prev->next; //m-1 node's next field as the head2 variable
            prev->next = cur;
            cur = mthNode->next;
        }
        return dummy.next;
    }
};