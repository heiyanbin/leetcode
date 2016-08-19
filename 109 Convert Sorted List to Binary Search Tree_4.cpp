// 109
// Convert Sorted List to Binary Search Tree
// https://leetcode.com//problems/convert-sorted-list-to-binary-search-tree/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head) return NULL;
        ListNode* p = head, *q=head, *prev = NULL;
        while(q&&q->next)
        {
            prev=p;
            p=p->next;
            q=q->next->next;
        }
        TreeNode* root = new TreeNode(p->val);
        if(prev)
            prev->next = NULL;
        else
            head = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(p->next);
    }
};