// 144
// Binary Tree Preorder Traversal
// https://leetcode.com//problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> traversal;
        if(!root) return traversal;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            root=s.top();
            s.pop();
            traversal.push_back(root->val);
            if(root->right) s.push(root->right);
            if(root->left) s.push(root->left);
        }
        return traversal;
    }
};