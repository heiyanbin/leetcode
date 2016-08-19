// 124
// Binary Tree Maximum Path Sum
// https://leetcode.com//problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        return dfs(root).first;
    }
private:
    pair<int, int> dfs(TreeNode *root) {
        if (root == nullptr) return make_pair(INT_MIN, 0);
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int pathSum2 = max(l.second, r.second) > 0 ? max(l.second, r.second) + root->val : root->val;
        int pathSum1 = root->val;
        if (l.second > 0) pathSum1 += l.second;
        if (r.second > 0) pathSum1 += r.second;
        return {max(pathSum1, max(l.first, r.first)), pathSum2};
    }

};