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
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            for (int levelSize = q.size(), i = 0; i < levelSize; ++ i){
                root = q.front(); q.pop();
                level.push_back(root -> val);
                if (root -> left) q.push(root -> left);
                if (root -> right) q.push(root -> right);
            }
            res.push_back(level);
        }
        return vector<vector<int>>(res.crbegin(), res.crend());
    }
};