// 107
// Binary Tree Level Order Traversal II
// https://leetcode.com//problems/binary-tree-level-order-traversal-ii/
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> output;
        if(!root) return output;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        TreeNode* endOfLevel= root;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            if(node==endOfLevel)
            {
                output.push_back(level);
                endOfLevel = q.back();
                level.clear();
            }
        }
        return vector<vector<int>>(output.crbegin(),output.crend());
    }
};