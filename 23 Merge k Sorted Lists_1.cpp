// 23
// Merge k Sorted Lists
// https://leetcode.com//problems/merge-k-sorted-lists/
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
    class cmp { public: bool operator()(ListNode* a, ListNode* b){return a->val > b->val;}};
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*,vector<ListNode*>, cmp> q;
        for_each(lists.begin(),lists.end(),[&q](ListNode* head){if(head) q.push(head);});
        return merge(q);
    }
    ListNode *merge(priority_queue<ListNode*,vector<ListNode*>, cmp> &lists)
    {
        if(lists.empty()) return NULL;
        auto head = lists.top();
        lists.pop();
        if(head->next)
            lists.push(head->next);
        head->next=merge(lists);
        return head;
    }
};