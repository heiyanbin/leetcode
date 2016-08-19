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
        dummy.next= head;
        for(auto p = head; p; )
        {
            int i=0;
            auto q =p;
            for(; q && i<k; i++)
                q=q->next;
            if(i<k) break; //last group less than k, don't reverse and all groups done
            ListNode * const firstNodeInGroup=p;
            for(p=p->next; p!=q; )
            {
                firstNodeInGroup->next = p->next; //use first node's next field as the next variable
                p->next=prev->next; //use left outer node's next field as the head2 variable
                prev->next = p;
                p= firstNodeInGroup->next;
            }
            prev= firstNodeInGroup;
        }
        return dummy.next;
    }
};