// 138
// Copy List with Random Pointer
// https://leetcode.com//problems/copy-list-with-random-pointer/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for(RandomListNode *cur=head;cur!=NULL;)
        {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next=cur->next;
            cur->next=node;
            cur=node->next;
        }
        for(RandomListNode *cur=head;cur!=NULL;)
        {
            if(cur->random)
                cur->next->random= cur->random->next;
            cur=cur->next->next;
        }
        RandomListNode dummy(-1);
        for(auto p=head,prev=&dummy;p;p=p->next)
        {
            prev->next=p->next;
            prev=prev->next;
            p->next=p->next->next;
        }
        return dummy.next;
    }
};