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
        vector<TreeNode*> v;
        pass(root, prev,v);
        if(v[0] && v[1])
        swap(v[0]->val, v[1]->val);
        
    }
    
    void pass(TreeNode* root, TreeNode* &prev, vector<TreeNode*> &v)
    {
        if(!root) return;
        
        pass(root->left,prev,v);
        if(prev && root->val<prev->val)
        {
            if(v.size()==0)
            {
                v.push_back(prev);
                v.push_back(root);
            }
            else
            {
                v[1]=root;
            }
        }
        prev=root;
        pass(root->right,prev,v);
    }
};