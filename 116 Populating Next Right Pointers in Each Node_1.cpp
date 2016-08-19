// 116
// Populating Next Right Pointers in Each Node
// https://leetcode.com//problems/populating-next-right-pointers-in-each-node/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect(root,NULL);
    }
    void connect(TreeLinkNode *root, TreeLinkNode* sibling)
    {
        if(!root) return;
        root->next = sibling;
        connect(root->left,root->right);
        connect(root->right,sibling ? sibling->left : NULL);
    }
};