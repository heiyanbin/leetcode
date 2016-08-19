// 24
// Swap Nodes in Pairs
// https://leetcode.com//problems/swap-nodes-in-pairs/
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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
    	dummy.next=head;
    	ListNode *prev=&dummy, *p=head;
    
    	while(p && p->next)
    	{
    		ListNode* second= p->next; //keep the right outer node
    		p->next=second->next; //connect the 1st node to the right outer node
    		second->next=p; //connect the 2nd node to the 1st node
    		prev->next=second; // connect the left outer node to the 2nd node
    		prev=p; //update left outer node
    		p=p->next;// update the current pointer
    	}
    	return dummy.next;
    }
};