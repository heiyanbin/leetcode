// 327
// Count of Range Sum
// https://leetcode.com//problems/count-of-range-sum/
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefixSum(nums.size());
        for (long long prev = 0, i = 0; i < nums.size(); ++i) {
            prefixSum[i] = prev + nums[i];
            prev = prefixSum[i];
        }
        root = insert(root, 0);
        int ans = 0;
        for (int i = 0; i < prefixSum.size(); ++i) {
            ans += i + 1 - (smaller(root, prefixSum[i] - upper) + greater(root, prefixSum[i] - lower));
            root = insert(root, prefixSum[i]);
        }
        return ans;
    }
    Solution() : root(nullptr) {}
private:
    struct TreeNode {
        long long val; 
        int size;
        TreeNode *left, *right;
        TreeNode(long long v) : val(v), size(1), left(nullptr), right(nullptr) {}
    };
    TreeNode *root;
    
    TreeNode *insert(TreeNode *root, long long v) {
        if (!root) return new TreeNode(v);
        if (v < root->val) root->left = insert(root->left, v);
        else root->right = insert(root->right, v);
        root->size += 1;
        return root;
    }
    
    int smaller(TreeNode* root, long long v) {
        if (!root) return 0;
        if (v <= root->val) return smaller(root->left, v);
        return size(root->left) + 1 + smaller(root->right, v);
    }
    
    int greater(TreeNode* root, long long v) {
        if (!root) return 0;
        if (v >= root->val) return greater(root->right, v);
        return size(root->right) + 1 + greater(root->left, v);
    }
    
    int size(TreeNode* node) { return node ? node->size : 0;}
    
};