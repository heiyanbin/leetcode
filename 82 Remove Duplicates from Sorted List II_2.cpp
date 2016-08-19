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
        if(!head||!head->next) return head;
        ListNode dummy(-1), *prev = &dummy, *cur=head;
        dummy.next=head;
        bool duplicate = false;
        while(cur->next)
        {
            if(cur->next->val==cur->val)
            {
                auto next = cur->next->next;
                delete cur->next;
                cur->next= next;
                duplicate= true;
            }
            else
            {
                if(duplicate)
                {
                    prev->next=cur->next;
                    delete cur;
                    cur=prev->next;
                    duplicate= false;
                }
                else
                {
                    prev=cur;
                    cur=cur->next;
                }
            }
        }
        if(duplicate)
        {
            prev->next=cur->next;
            delete cur;
        }
        return dummy.next;
    }
};