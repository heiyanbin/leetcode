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
        if(!root) return;
        TreeLinkNode *head = root;
        while(head)
        {
            TreeLinkNode *p = head;
            TreeLinkNode *prev = NULL;
            head = NULL;
            while(p)
            {
                if(p->left)
                {
                    if(prev != NULL)
                    {
                        prev->next = p->left;
                    }
                    else
                    {
                        head = p->left;
                    }
                    prev = p->left;
                }
                if(p->right)
                {
                    if(prev != NULL)
                    {
                        prev->next = p->right;
                    }
                    else
                    {
                        head = p->right;
                    }
                    prev = p->right;
                }
                p=p->next;
            }
        }
        
    }
};