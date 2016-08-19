// 94
// Binary Tree Inorder Traversal
// https://leetcode.com//problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> output;
        vector<TreeNode*> stack;
        while(root || !stack.empty()) //top of the stack stores next candidate of the previous level
        {
            if(root)
            {
                stack.push_back(root);
                root = root->left;
            }
            else
            {
                root = stack.back();
                stack.pop_back();
                output.push_back(root->val);
                root = root->right;
            }
        }
        return output;
        
    }
};