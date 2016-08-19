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
    void flatten(TreeNode *root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right); 
        TreeNode *p = root->left;
        if(root->left==NULL) return;
        while( p->right)
            p=p->right;
        p->right= root->right;
        root->right= root->left;
        root->left=NULL;
        
    }
};