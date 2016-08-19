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
        int sum=root->val;
        if(l>0) sum+=l;
        if(r>0) sum+=r;
        maxSum=max(maxSum, sum);
        return max(l,r)>0 ? max(l,r)+root->val : root->val;
    }
};