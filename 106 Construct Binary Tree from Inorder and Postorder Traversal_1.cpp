// 106
// Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com//problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty()||postorder.empty()) return NULL;
        return buildTree(inorder,0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode *buildTree(vector<int> &inorder, int i, int j, vector<int> &postorder, int k, int m)
     {
        if(i>j||k>m) return NULL;
        TreeNode* root = new TreeNode(postorder[m]);
        int t=i;
        while(t<=j && inorder[t]!=postorder[m])
            t++;
        assert(t<=j);
        root->left= buildTree(inorder, i, t-1, postorder, k, k+t-i-1);
        root->right=buildTree(inorder, t+1, j, postorder, k+t-i, m-1);
        return root;
     }
};