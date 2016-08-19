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
        vector<int> res;
        if (root == NULL) return res;
        stack<pair<TreeNode*, int>> stack;
        for (stack.push(make_pair(root, 0)); !stack.empty();) {
            auto &cur = stack.top();
            if (cur.second == 0) {
                if (cur.first -> left) stack.push(make_pair(cur.first -> left, 0));
            } else if (cur.second == 1) {
                if (cur.first -> right) stack.push(make_pair(cur.first -> right, 0));
            } else {
                res.push_back(cur.first -> val);
                stack.pop();
            }
            cur.second++;
        }
        return res;
    }
};