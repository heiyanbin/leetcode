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
        map<int,int> mp;
        ListNode *p =head, *prev=NULL;
        while(p)
        {
            if(mp.count(p->val)>0)
            {
                ListNode *next = p->next;
                delete p;
                prev->next = next;
                p=next;
            }
            else
            {
                mp[p->val]++;
                prev = p;
                p=p->next;
                
            }
        }
        return head;
    }
};