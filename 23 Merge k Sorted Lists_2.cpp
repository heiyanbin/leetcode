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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0) return NULL;
        make_heap(lists.begin(),lists.end(),Solution::compare);
        while(!lists.empty() && lists.front()==NULL)
        {
            pop_heap(lists.begin(),lists.end(),Solution::compare);
            lists.pop_back();
        }
        return merge(lists);      
    }
    ListNode *merge(vector<ListNode *> &lists)
    {
        if(lists.empty()) return NULL;
        pop_heap(lists.begin(),lists.end(),Solution::compare);
        ListNode* head = lists.back();
        if(lists.back()->next)
        {
            lists.back() = lists.back()->next;
            push_heap(lists.begin(),lists.end(),Solution::compare);
        }
        else
            lists.pop_back();
        head->next=merge(lists);
        return head;
    }
    static bool compare(ListNode* a, ListNode* b)
    {
        if(!a) return false;
        if(!b) return true;
        return a->val > b->val;
    }
};