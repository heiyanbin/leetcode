// 98
// Validate Binary Search Tree
// https://leetcode.com//problems/validate-binary-search-tree/
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
    bool isValidBST(TreeNode *root) {
        if(!root) return true;
        validate(root);
        return result;
    }
    void validate(TreeNode *root)
    {
        if(!root) return;
        validate(root->left);
        if(prev && prev->val>=root->val)
            result = false;
        else
        {
            prev=root;
            validate(root->right);
        }
        
    }
    Solution():prev(NULL),result(true){}
private:
    TreeNode* prev;
    bool result;
};