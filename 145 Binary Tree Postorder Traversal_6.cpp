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
        vector<bool> stack2;
        vector<int> tranversal;
        while(root || !stack.empty())
        {
            if(root)
            {
                stack.push_back(root);
                stack2.push_back(false);
                root=root->left;
            }
            else
            {
                root = stack.back();
                stack.pop_back();
                bool access = stack2.back();
                stack2.pop_back();
                if(access||root->right==NULL)
                {
                    tranversal.push_back(root->val);
                    root=NULL;
                }
                else
                {
                    stack.push_back(root);
                    stack2.push_back(true);
                    root=root->right;
                }
            }
        }
        return tranversal;
    }
};