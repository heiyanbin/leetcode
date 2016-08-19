// 98
// Validate Binary Search Tree
// https://leetcode.com//problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode *root) {
        if(!root) return true;
        if(!isValidBST(root->left)||!isValidBST(root->right)) return false;
        TreeNode *p= root->left;
        while(p &&p->right)
            p=p->right;
        if(p&& root->val<=p->val) return false;
        p=root->right;
        while(p&& p->left)
            p=p->left;
        if(p&& root->val>=p->val) return false;
        
        return true;
    }

};