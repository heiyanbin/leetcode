// 102
// Binary Tree Level Order Traversal
// https://leetcode.com//problems/binary-tree-level-order-traversal/
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> output;
        if(!root) return output;
        queue<TreeNode*> q;
        q.push(root);
        int currentLevelCount=1;
        int nextLevelCount =0;
        vector<int> level;
        while(!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left)
            {
                q.push(node->left);
                nextLevelCount++;
            }
            if(node->right)
            {
                q.push(node->right);
                nextLevelCount++;
            }
            currentLevelCount--;
            if(currentLevelCount==0)
            {
                currentLevelCount=nextLevelCount;
                nextLevelCount=0;
                output.push_back(level);
                level.clear();
            }
        }
        return output;
    }
};