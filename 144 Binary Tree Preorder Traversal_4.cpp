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
        vector<int> tranversal;
        
        vector<TreeNode*> v;
        while(root || !v.empty())
        {
            if(root)
            {
                tranversal.push_back(root->val);
                if(root->right)
                    v.push_back(root->right);
                root=root->left;
            }
            else
            {
                root = v.back();
                v.pop_back();
            }
        }
        return tranversal;
    }
};