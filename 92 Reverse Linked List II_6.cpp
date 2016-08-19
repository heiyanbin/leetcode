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
        if(!head) return head;
        if(m==n) return head;
        int nodeNum =1;
        ListNode* p = head, *prev = NULL;
        
        while(nodeNum < m)
        {
            prev=p;
            p=p->next;
            nodeNum++;
        }
        ListNode * head2 = p;
        p=p->next;
        nodeNum++;
        while(p && nodeNum<=n)
        {
            ListNode* next = p->next;
            p->next = head2;
            head2 = p;
            p=next;
            nodeNum++;
        }
        if(prev)
        {
            prev->next->next=p;
            prev->next = head2;
        }
        else
        {
            head->next = p;
            head=head2;
        }
        return head;
    }
};