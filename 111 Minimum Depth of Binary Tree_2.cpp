// 111
// Minimum Depth of Binary Tree
// https://leetcode.com//problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        int a = minDepth(root->left);
        int b = minDepth(root->right);
        if(!root->left) return b+1;
        if(!root->right) return a+1;
        return  a < b ? a+1 : b+1 ;
    }
};