// 129
// Sum Root to Leaf Numbers
// https://leetcode.com//problems/sum-root-to-leaf-numbers/
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
    int sumNumbers(TreeNode *root) {
        dfs(root,0);
        return sum;
    }
private:
    int sum;
    void dfs(TreeNode *root,int value)
    {
        if(!root) return;
        value=value*10+root->val;
        if(!root->left && !root->right)
            sum+=value;
        dfs(root->left,value);
        dfs(root->right,value);
    }
};