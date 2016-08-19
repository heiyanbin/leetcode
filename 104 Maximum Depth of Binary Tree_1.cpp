// 104
// Maximum Depth of Binary Tree
// https://leetcode.com//problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        int a = maxDepth(root->left);
        int b = maxDepth(root->right);
        return max(a,b)+1;
    }
};