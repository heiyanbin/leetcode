// 99
// Recover Binary Search Tree
// https://leetcode.com//problems/recover-binary-search-tree/
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
    void recoverTree(TreeNode *root) {
        if (!root) return;
        TreeNode* prev = NULL;
        vector<TreeNode*> v;
        dfs(root, prev, v);
        if(!v.empty()) 
            swap(v[0]->val, v[1]->val);
    }
    
    void dfs(TreeNode* root, TreeNode* &prev, vector<TreeNode*> &v) {
        if (!root) return;
        dfs(root -> left, prev, v);
        if (prev && root -> val < prev -> val) {
            if (v.empty()) {
                v.push_back(prev);
                v.push_back(root);
            } else
                v[1]=root;
        }
        prev = root;
        dfs(root -> right, prev, v);
    }
};