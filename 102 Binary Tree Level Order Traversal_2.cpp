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
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level; 
            for (int i = 0, levelSize = q.size(); i < levelSize; ++i) {
                root = q.front(); q.pop();
                level.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            res.push_back(level);
        }
        return res;
    }
};