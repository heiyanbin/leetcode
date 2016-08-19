// 222
// Count Complete Tree Nodes
// https://leetcode.com//problems/count-complete-tree-nodes/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = left(root -> left );
        int r = right(root -> left);
        if (l == r) return pow(2, l) - 1 + countNodes(root -> right) + 1;
        if (l > r) return countNodes(root -> left) + pow(2, r) - 1 + 1;
    }
    
    int right(TreeNode* root) {
        if (root == nullptr) return 0;
        return right(root -> right) + 1;
    }
    
    int left(TreeNode *root) {
        if (root == nullptr) return 0;
        return left(root -> left) + 1;
    }
};