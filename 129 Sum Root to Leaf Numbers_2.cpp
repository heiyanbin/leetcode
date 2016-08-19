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
        getSum(root);
        return sum;
    }

    void getSum(TreeNode * root)
    {
        if(!root) return;
        num = num *10 + root->val;
        if(!root->left && !root->right)
            sum += num;
        else
        {
            getSum(root->left);
            getSum(root->right);
        }
        num = (num -root->val)/10;
    }
private:
    int sum;
    int num;
};