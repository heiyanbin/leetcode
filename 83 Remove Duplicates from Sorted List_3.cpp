// 83
// Remove Duplicates from Sorted List
// https://leetcode.com//problems/remove-duplicates-from-sorted-list/
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
        if(head==NULL) return NULL;
        for(ListNode *prev=head,*cur=head->next;cur;cur=cur->next)
        {
            if(prev->val==cur->val)
            {
                prev->next = cur->next;
                delete cur;
            }
            else
                prev=cur;   
        }
        return head;
    }
};