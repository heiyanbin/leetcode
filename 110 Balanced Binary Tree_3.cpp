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
    
    int balancedDepth(TreeNode* root)
    {
        if(!root) return 0;
        int left= balancedDepth(root->left);
        int right= balancedDepth(root->right);
        if(left<0 || right < 0 || abs(left-right)>1) return -1;
        return max(left,right) + 1;
    }
};