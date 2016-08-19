// 145
// Binary Tree Postorder Traversal
// https://leetcode.com//problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<TreeNode*> stack;
        vector<int> tranversal;
        TreeNode* prev= NULL;
        while(root || !stack.empty())
        {
            if(root)
            {
                stack.push_back(root);
                root=root->left;
            }
            else
            {
                root = stack.back();
                stack.pop_back();
                if(root->right==NULL || prev==root->right)
                {
                    tranversal.push_back(root->val);
                    prev=root;
                    root=NULL;
                }
                else
                {
                    stack.push_back(root);
                    root=root->right;
                }
            }
        }
        return tranversal;
    }
};