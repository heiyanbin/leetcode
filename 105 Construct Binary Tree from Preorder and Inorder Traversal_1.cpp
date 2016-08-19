// 105
// Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com//problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty()||inorder.empty()) return NULL;
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
     TreeNode *buildTree(vector<int> &preorder, int i, int j, vector<int> &inorder, int k, int m)
     {
        if(i>j||k>m) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        int t=k;
        while(t<=m && inorder[t]!=preorder[i])
            t++;
        assert(t<=m);
        root->left= buildTree(preorder, i+1, i+t-k, inorder, k, t-1);
        root->right=buildTree(preorder, i+t-k+1, j, inorder, t+1, m);
        return root;
     }
};