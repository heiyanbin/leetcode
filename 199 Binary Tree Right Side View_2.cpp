// 199
// Binary Tree Right Side View
// https://leetcode.com//problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = 0, levelSize = q.size(); i < levelSize; ++i) {
                root = q.front(); q.pop();
                if (i == levelSize - 1) res.push_back(root -> val);
                if (root -> left) q.push(root -> left);
                if (root -> right) q.push(root -> right);
            }
        }
        return res;
    }
};