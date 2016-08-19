// 145
// Binary Tree Postorder Traversal
// https://leetcode.com//problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> stack;
        vector<int> traversal;
        TreeNode* prev = NULL;
        while (root || !stack.empty()) {
            if (root) {
                stack.push(root);
                root = root -> left;
            }
            else {
                root = stack.top(); stack.pop();
                if (root -> right == NULL || prev == root -> right) {
                    traversal.push_back(root -> val);
                    prev = root;
                    root = NULL;
                } else {
                    stack.push(root);
                    root = root -> right;
                }
            }
        }
        return traversal;
    }
};