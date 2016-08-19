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
        ListNode dummy(-1);
        dummy.next= head;
        ListNode *prev= &dummy;
        ListNode *p = head;
        while(p)
        {
            ListNode *q =p;
            int i=0;
            while(q && i<k)
            {
                q=q->next;
                i++;
            }
            if(i<k)
                break;
            ListNode  * const head2=prev, * const firstNode=p;
            p=p->next;
            while(p!=q)
            {
                firstNode->next = p->next;
                p->next=head2->next;
                head2->next = p;
                p=firstNode->next;
            }
            prev=firstNode;
        }
        return dummy.next;
    }
};