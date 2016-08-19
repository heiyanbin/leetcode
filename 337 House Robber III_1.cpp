// 337
// House Robber III
// https://leetcode.com//problems/house-robber-iii/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        auto it = cache.find(root);
        if (it != cache.end()) return it->second;
        
        return cache[root] = max(rob(root, true), rob(root, false));
    }
private:
    int rob(TreeNode* root, bool robRoot) {
        if (!root) return 0;
        if (robRoot) return root->val + rob(root->left, false) + rob(root->right, false);
        return rob(root->left) + rob(root->right);
    }
    
    unordered_map<TreeNode*, int> cache;
};