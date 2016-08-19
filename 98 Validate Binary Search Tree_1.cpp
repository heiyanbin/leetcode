// 98
// Validate Binary Search Tree
// https://leetcode.com//problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        return isValidBST(root->right);
    }
    Solution() : pre(nullptr) {}
private:
    TreeNode *pre;
};