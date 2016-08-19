// 199
// Binary Tree Right Side View
// https://leetcode.com//problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
    void dfs(TreeNode* root, int level, vector<int> &res) {
        if (root == nullptr) return;
        
        if (level == res.size()) 
            res.push_back(root -> val);
        else 
            res[level] = root -> val;
        
        dfs(root -> left, level + 1, res);
        dfs(root -> right, level + 1, res);
    }
};