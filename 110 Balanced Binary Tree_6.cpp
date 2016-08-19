// 110
// Balanced Binary Tree
// https://leetcode.com//problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode *root) {
        if(!root) return true;
        int a = depth(root->left);
        int b = depth(root->right);
        if(abs(a-b)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int depth(TreeNode* root)
    {
        if(!root) return 0;
        return max(depth(root->left), depth(root->right)) +1;
    }
};