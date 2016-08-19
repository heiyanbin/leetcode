// 102
// Binary Tree Level Order Traversal
// https://leetcode.com//problems/binary-tree-level-order-traversal/
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
    void dfs(TreeNode* root, int level, vector<vector<int>> &res) {
        if (!root) return;
        if (level == res.size()) res.push_back(vector<int>());
        res[level].push_back(root -> val);
        dfs(root -> left, level + 1, res);
        dfs(root -> right, level + 1, res);
    }
};