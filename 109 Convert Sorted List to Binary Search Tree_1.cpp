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
        if (!head) return nullptr;
        struct R {
            TreeNode* root;
            ListNode *next;
            R(TreeNode *r, ListNode* t): root(r), next(t) {}
        };
        function<R (ListNode*, int)> convert = [&](ListNode * head, int n) -> R{
            if (n == 0) return R(nullptr, head);
            auto leftR = convert(head, n / 2);
            auto root = new TreeNode(leftR.next->val);
            root->left = leftR.root;
            auto  rightR= convert(leftR.next->next, n - 1 - n / 2);
            root->right = rightR.root;
            return R(root, rightR.next);
        };
        int len = 0;
        for (auto p = head; p ; ++len, p = p->next) ;
        return convert(head, len).root;
    }
    
};