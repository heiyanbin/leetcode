// 114
// Flatten Binary Tree to Linked List
// https://leetcode.com//problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode *x) {
        function<pair<TreeNode*, TreeNode*>(TreeNode*)> f = [&](TreeNode* root){
            if (!root) return pair<TreeNode*, TreeNode*>(nullptr, nullptr);
            auto left = f(root -> left);
            auto right = f(root -> right);
            if (left.second) {
                left.second -> right = right.first;
                root -> right = left.first;
            } else {
                root -> right = right.first;
            }
            root -> left = nullptr;
            return make_pair(root, right.second ? right.second : (left.second ? left.second : root));
        };
        f(x);
    }
};