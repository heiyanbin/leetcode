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
        for(auto cur=head; cur;)
        {
            auto node = new RandomListNode(cur->label);
            node->next=cur->next;
            cur->next=node;
            cur=node->next;
        }
        for(auto cur=head; cur; cur=cur->next->next)
            if(cur->random)
                cur->next->random= cur->random->next;
                
        RandomListNode dummy(-1);
        for(auto cur=head,prev=&dummy; cur; prev=prev->next, cur=cur->next)
        {
            prev->next=cur->next;
            cur->next=cur->next->next;
        }
        return dummy.next;
    }
};