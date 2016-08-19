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
        if(head==NULL || head->next==NULL)
            return head;
        unordered_map<int,int> map;
        ListNode* p=head;
        while(p)
        {
            map[p->val]++;
            p=p->next;
        }
        ListNode* fakeHead = new ListNode(0);
        p=fakeHead;
        p->next=head;
        while(p->next)
        {
            if(map[p->next->val]>1)
            {
                ListNode * del =p->next;
                p->next= del->next;
                delete del;
            }
            else
                p=p->next;
        }
        return fakeHead->next;
    }
};