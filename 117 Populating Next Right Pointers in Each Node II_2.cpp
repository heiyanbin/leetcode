// 117
// Populating Next Right Pointers in Each Node II
// https://leetcode.com//problems/populating-next-right-pointers-in-each-node-ii/
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
        vector<TreeLinkNode*> levelPrev;
        connect(root, levelPrev, 0);
    }
    void connect(TreeLinkNode *root, vector<TreeLinkNode*> &levelPrev, int level)
    {
        if(!root) return;
        if(level==levelPrev.size())
            levelPrev.push_back(root);
        else
        {
            levelPrev[level]->next = root;
            levelPrev[level]=root;
        }
        connect(root->left, levelPrev,level+1);
        connect(root->right, levelPrev,level+1);
    }
};