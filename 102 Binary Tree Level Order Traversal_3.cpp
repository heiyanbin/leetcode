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
        vector<vector<int>> output;
        if(!root) return output;
        queue<TreeNode*> q;
        q.push(root);
        auto levelEnd = root;
        vector<int> level;
        while(!q.empty())
        {
            root = q.front();
            q.pop();
            level.push_back(root->val);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            if(root==levelEnd)
            {
                output.push_back(level);
                level.clear();
                if(!q.empty())
                    levelEnd = q.back();
            }
        }
        return output;
    }
};