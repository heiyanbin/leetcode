// 315
// Count of Smaller Numbers After Self
// https://leetcode.com//problems/count-of-smaller-numbers-after-self/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        root = nullptr;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] = rank(root, nums[i]);
            root = insert(root, nums[i]);
        }
        return ans;
    }
private:
    struct TreeNode {
        int val, size;
        TreeNode *left, *right;
        TreeNode(int v) : val(v), size(1), left(NULL), right(NULL) {}
    };
    TreeNode* root;
    TreeNode* insert(TreeNode *root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (val < root->val) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        root->size += 1;
        return root;
    }
    int rank(TreeNode *root, int val) {
        if (root == nullptr) return 0;
        if (val <= root->val) return rank(root->left, val);
        else return (root->left ? root->left->size : 0) + 1 + rank(root->right, val);
    }
};