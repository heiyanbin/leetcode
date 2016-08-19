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
        auto head = root;
        while (head ) {
            TreeLinkNode dummy(-1);
            for (TreeLinkNode *p = head, *prev = &dummy; p; p = p->next) {
                if (p->left) {
                    prev->next = p->left;
                    prev = prev->next;
                }
                if (p->right) {
                    prev->next = p->right;
                    prev = prev->next;
                }
            }
            head = dummy.next;
        }
    }
};