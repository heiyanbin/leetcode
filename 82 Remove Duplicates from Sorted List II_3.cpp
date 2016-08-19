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
        ListNode fakeHead(-1);
        fakeHead.next=head;
        for(ListNode *prev=&fakeHead,*cur=head;cur;cur=cur->next)
        {
            if(map[cur->val]>1)
            {
                prev->next= cur->next;
                delete cur;
                cur=prev;
            }
            else
                prev=cur;
        }
        return fakeHead.next;
    }
};