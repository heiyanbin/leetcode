// 113
// Path Sum II
// https://leetcode.com//problems/path-sum-ii/
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > allPath;
        vector<int> curPath;
        findPath(root, sum, curPath, allPath);
        return allPath;
    }
    void findPath(TreeNode *root, int sum, vector<int> &curPath, vector<vector<int> > &allPath)
    {
        if(!root) return;
        curPath.push_back(root->val);
        sum-=root->val;
        if(sum==0 && !root->left && !root->right)
            allPath.push_back(curPath);
        findPath(root->left, sum, curPath, allPath);
        findPath(root->right, sum, curPath, allPath);
        curPath.pop_back();
        sum+=root->val;
    }
};