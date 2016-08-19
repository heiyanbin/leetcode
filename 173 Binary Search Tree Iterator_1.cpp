// 173
// Binary Search Tree Iterator
// https://leetcode.com//problems/binary-search-tree-iterator/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        this->root = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return root || !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top(); s.pop();
                int ret = root->val;
                root = root->right;
                return ret;
            }
        }
    }
private:
    TreeNode *root;
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */