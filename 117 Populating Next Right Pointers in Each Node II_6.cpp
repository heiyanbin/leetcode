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
        TreeLinkNode *head = root;
        while(head)
        {
            TreeLinkNode *p=head, *prev=NULL;
            head = NULL;
            while(p)
            {
                if(p->left)
                {
                    if(prev==NULL)
                    {
                        head= p->left;
                    }
                    else
                    {
                        prev->next= p->left;
                    }
                    prev= p->left;
                }
                if(p->right)
                {
                    if(prev==NULL)
                    {
                        head=p->right;
                    }
                    else
                    {
                        prev->next=p->right;
                    }
                    prev=p->right;
                }
                p=p->next;
            }
        }
    }
};