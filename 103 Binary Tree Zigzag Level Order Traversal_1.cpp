// 103
// Binary Tree Zigzag Level Order Traversal
// https://leetcode.com//problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            vector<int> lv;
            for (int i = 0, levelSize = q.size(); i < levelSize; ++i) {
                root = q.front(); q.pop();
                lv.push_back(root -> val);
                if (root -> left) q.push(root -> left);
                if (root -> right) q.push(root -> right);
            }
            if (level & 1) reverse(lv.begin(), lv.end());
            res.push_back(lv);
            ++ level;
        }
        return res;
    }
};