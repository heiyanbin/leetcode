// 114
// Flatten Binary Tree to Linked List
// https://leetcode.com//problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode *root) {
    flatten(root, NULL);
}
private:
    // 把root 所代表树变成链表后，tail 跟在该链表后面
    TreeNode *flatten(TreeNode *root, TreeNode *tail) {
    if (NULL == root) return tail;
    root->right = flatten(root->left, flatten(root->right, tail));
    root->left = NULL;
    return root;
}
};