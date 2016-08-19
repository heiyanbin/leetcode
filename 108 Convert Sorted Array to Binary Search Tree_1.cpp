// 108
// Convert Sorted Array to Binary Search Tree
// https://leetcode.com//problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode *sortedArrayToBST(vector<int> &num) {

        return make(num, 0, num.size()-1);
        
    }
    
    TreeNode * make(vector<int> &num, int start, int end)
    {
        if(start>end) return NULL;
        int mid = (start + end)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = make(num,start, mid-1);
        root->right = make(num, mid+1,end);
        return root;
    }
};