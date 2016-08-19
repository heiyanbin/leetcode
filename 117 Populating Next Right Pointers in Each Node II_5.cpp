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
    if (root == NULL) return;
    TreeLinkNode * start = root;
    TreeLinkNode * end = root;
    TreeLinkNode * levelEnd = root;
    while (start != NULL)
    {
        if (start->left != NULL)
        {
            end->next = start->left;
            end = end->next;
        }
        if (start->right != NULL)
        {
            end->next = start->right;
            end = end->next;
        }
        if (start == levelEnd)
        {
            start = start->next;
            levelEnd->next = NULL;
            levelEnd = end;
        }
        else
        {
            start = start->next;
        }
    }
}
};