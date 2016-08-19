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
        int minDepth=INT_MAX;
        dfs(root,1,minDepth);
        return minDepth==INT_MAX ? 0 : minDepth;
    }
    void dfs(TreeNode *root, int level, int &minDepth)
    {
        if(!root) return;
        if(!root->left && !root->right)
            minDepth=min(minDepth,level);
        dfs(root->left,level+1,minDepth);
        dfs(root->right,level+1,minDepth);
    }
};