// 156
// Binary Tree Upside Down
// https://leetcode.com//problems/binary-tree-upside-down/
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
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if(root==NULL || root->left==NULL) return root;
        auto l = root->left, r= root->right;
        root->left=NULL;
        root->right=NULL;
        return rotate(l, r, root);
    }
    TreeNode* rotate(TreeNode* left, TreeNode* right, TreeNode* root)
    {
        auto l = left->left, r= left->right;
        left->left=right;
        left->right=root;
        if(l==NULL) return left;
        return rotate(l,r,left);
    }
};