// 110
// Balanced Binary Tree
// https://leetcode.com//problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode *root) {
        bool balanced = true;
        depth(root, balanced);
        return balanced;
        
    }
    
    int depth(TreeNode* root,bool &balanced)
    {
        if(!root) return 0;
        int left= depth(root->left,balanced);
        int right= depth(root->right,balanced);
        if(left>=0 && right >=0 )  
        {
            if(abs(left-right)>1)
            {   
                balanced = false;
                return -1;
            }
            return max(left,right)+1;
        }
        return -1;
    }
};