// 144
// Binary Tree Preorder Traversal
// https://leetcode.com//problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> traversal;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                traversal.push_back(root -> val);
                if (root -> right) s.push(root -> right);
                root = root -> left;
            } else {
                root = s.top(); s.pop();
            }
        }
        return traversal;
    }
};