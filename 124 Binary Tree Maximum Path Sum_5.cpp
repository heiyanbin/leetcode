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
        if(!root) return 0;
        int globalMaxSum = root->val;
        maxPathSumFromRoot(root, globalMaxSum);
        return globalMaxSum;
    }
    
    int maxPathSumFromRoot(TreeNode * root, int &globalMaxSum)
    {
        if(root==NULL) return 0;
        
        int maxSum = root->val;
        int leftSum = maxPathSumFromRoot(root->left,globalMaxSum)+root->val;
        if(leftSum>maxSum)
            maxSum = leftSum;
        int rightSum = maxPathSumFromRoot(root->right,globalMaxSum)+root->val;
        if( rightSum>maxSum)
            maxSum = rightSum;
        int allSum = leftSum - root->val + rightSum;
        if(allSum > globalMaxSum)
            globalMaxSum= allSum;
        if(maxSum>globalMaxSum)
            globalMaxSum = maxSum;
        return maxSum;
    }
};