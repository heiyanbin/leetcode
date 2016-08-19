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
    void connect(TreeLinkNode *root) 
    {
        TreeLinkNode *head = root, *levelEnd = root, *end =root;
        while (head)
        {
            if (head->left)
            {
                end->next = head->left;
                end = end->next;
            }
            if (head->right)
            {
                end->next = head->right;
                end = end->next;
            }
            if (head == levelEnd)
            {
                head = head->next;
                levelEnd->next = NULL;
                levelEnd = end;
            }
            else
            {
                head = head->next;
            }
        }
    }
};