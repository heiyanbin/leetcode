// 124
// Binary Tree Maximum Path Sum
// https://leetcode.com//problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        maxPathSumFromRoot(root, maxSum);
        return maxSum;
    }
    
    int maxPathSumFromRoot(TreeNode * root, int &maxSum)
    {
        if(root==NULL) return 0;
        int l= maxPathSumFromRoot(root->left,maxSum);
        int r= maxPathSumFromRoot(root->right,maxSum);
        maxSum=max(maxSum, l+root->val+r);
        int ret = root->val + max(l,r);
        return ret>0 ? ret : 0;
    }
};