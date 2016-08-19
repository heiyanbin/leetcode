// 95
// Unique Binary Search Trees II
// https://leetcode.com//problems/unique-binary-search-trees-ii/
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
    vector<TreeNode *> generateTrees(int n) {
        if(n<=0) return vector<TreeNode*>(1,nullptr);
        return generate(1,n);
    }
    vector<TreeNode*> generate(int start, int end)
    {
        vector<TreeNode*> trees;
        if(start>end)
        {
            trees.push_back(nullptr);
            return trees;
        }
        for(int k=start;k<=end;k++)
        {
            auto leftTrees = generate(start,k-1);
            auto rightTrees = generate(k+1,end);
            for (auto left: leftTrees)
                for(auto right: rightTrees)
                {
                    auto root= new TreeNode(k);
                    root->left = left;
                    root->right= right;
                    trees.push_back(root);
                }
        }
        return trees;
    }
};