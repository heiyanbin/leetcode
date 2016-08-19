// 148
// Sort List
// https://leetcode.com//problems/sort-list/
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return qsort(head, NULL);
    }
    ListNode *qsort(ListNode *head, ListNode *end_exclusive)
    {
        if(head==end_exclusive || head->next ==end_exclusive) return head;
        ListNode left_dummy(-1), right_dummy(-1);
        right_dummy.next = head;
        ListNode *cur_left=&left_dummy, *cur_right=head;
        for(auto p = head->next;p!=end_exclusive;)
        {
            auto next = p->next;
            if(p->val < head->val)
            {
                cur_left->next=p;
                cur_left=p;
            }
            else if(p->val> head->val)
            {
                cur_right->next=p;
                cur_right=p;
            }
            else
            {
                p->next=right_dummy.next;
                right_dummy.next=p;
            }
            p=next;
        }
        cur_right->next=end_exclusive;
        cur_left->next=right_dummy.next;
        head->next= qsort(head->next,end_exclusive);
        return qsort(left_dummy.next,cur_left->next);
    }
};