// 101
// Symmetric Tree
// https://leetcode.com//problems/symmetric-tree/
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
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        vector<TreeNode *> v1,v2;
        preOrder1(root, v1);
        preOrder2(root, v2);
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]==NULL && v2[i]!=NULL) return false;
            if(v1[i]!=NULL && v2[i]==NULL) return false;
            if(v1[i]==NULL && v2[i]==NULL) continue;
            if(v1[i]->val!=v2[i]->val) return false;
        }
        return true;
    }
    
    void preOrder1(TreeNode *root, vector<TreeNode*> &v)
    {
        if(!root) 
        {
            v.push_back(NULL);
            return;
        }
        v.push_back(root);
        preOrder1(root->left, v);
        preOrder1(root->right,v);
    }
    void preOrder2(TreeNode *root, vector<TreeNode*> &v)
    {
        if(!root) 
        {
            v.push_back(NULL);
            return;
        }
        v.push_back(root);
        preOrder2(root->right, v);
        preOrder2(root->left,v);
    }
};