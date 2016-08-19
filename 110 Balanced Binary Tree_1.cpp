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
        return balancedDepth(root) != -1;
    }
    
    int balancedDepth(TreeNode* root) {
        if (!root) return 0;
        int l = balancedDepth(root -> left);
        if (l < 0) return -1;
        int r = balancedDepth(root -> right);
        if (r < 0 || abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }
};