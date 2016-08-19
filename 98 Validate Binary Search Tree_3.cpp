// 98
// Validate Binary Search Tree
// https://leetcode.com//problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode *root) {
        return validBST(root,INT_MIN, INT_MAX);
    }
    bool validBST(TreeNode* root, int leftBound, int rightBound)
    {
        if(!root) return true;
        if(root->val>=rightBound || root->val <= leftBound) return false;
        return validBST(root->left,leftBound,root->val) && validBST(root->right,root->val,rightBound);
    }
};