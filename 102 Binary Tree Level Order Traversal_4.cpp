// 102
// Binary Tree Level Order Traversal
// https://leetcode.com//problems/binary-tree-level-order-traversal/
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        tranverse(root,0);
        return output;
    }
    void tranverse(TreeNode* root, int level)
    {
        if(!root) return;
        if(level==output.size())
            output.push_back(vector<int>());
        output[level].push_back(root->val);
        tranverse(root->left,level+1);
        tranverse(root->right,level+1);
    }
private:
    vector<vector<int>> output;
};