// 86
// Partition List
// https://leetcode.com//problems/partition-list/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head||!head->next) return head;
        ListNode dummy_left(-1),dummy_right(-1);
        ListNode *cur_left = &dummy_left, *cur_right = &dummy_right;
        while(head)
        {
            if(head->val<x)
            {
                cur_left->next=head;
                cur_left=head;
            }
            else
            {
                cur_right->next=head;
                cur_right=head;
            }
            head=head->next;
        }
        cur_left->next=dummy_right.next;
        cur_right->next= NULL;
        return dummy_left.next;
    }
};