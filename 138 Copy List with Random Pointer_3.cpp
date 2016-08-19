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
        if(!head) return NULL;
        map<RandomListNode*, RandomListNode*> mp;
        RandomListNode *head2 = new RandomListNode(head->label);
        head2->random=head->random;
        mp[head]=head2;
        RandomListNode *p= head2;
        head=head->next;
        while(head)
        {
            p->next=new RandomListNode(head->label);
            p->next->random= head->random;
            mp[head]=p->next;
            head=head->next;
            p=p->next;
        }
        p=head2;
        while(p)
        {
            p->random=mp[p->random];
            p=p->next;
        }
        return head2;
    }
};