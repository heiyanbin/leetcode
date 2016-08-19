// 99
// Recover Binary Search Tree
// https://leetcode.com//problems/recover-binary-search-tree/
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
    void recoverTree(TreeNode *root) {
        if(!root) return;
        TreeNode* prev = NULL;
        pair<TreeNode*,TreeNode*> swapped(NULL,NULL);
        inOrder(root, prev, swapped);
        if(swapped.first && swapped.second)
        swap(swapped.first->val, swapped.second->val);
        
    }
    
    void inOrder(TreeNode* root, TreeNode* &prev, pair<TreeNode*,TreeNode*> &swapped)
    {
        if(!root) return;
        inOrder(root->left,prev,swapped);
        if(prev && root->val<prev->val)
        {
            if(swapped.first==NULL)
            {
                swapped.first=prev;
                swapped.second=root;
            }
            else
                swapped.second = root;
        }
        prev=root;
        inOrder(root->right,prev,swapped);
    }
};