// 101
// Symmetric Tree
// https://leetcode.com//problems/symmetric-tree/
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
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return isMirrorTree(root->left,root->right);
    }
    bool isMirrorTree(TreeNode *a, TreeNode* b)
    {
        if(!a && !b) return true;
        if(!a && b) return false;
        if(a && !b) return false;
        if(a->val!=b->val) return false;
        return isMirrorTree(a->left, b->right) && isMirrorTree(a->right, b->left);
    }
};