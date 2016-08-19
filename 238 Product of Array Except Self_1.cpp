// 238
// Product of Array Except Self
// https://leetcode.com//problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0, left = 1; i < nums.size(); ++i) {
            ans[i] = left;
            left *= nums[i];
        }
        for (int i = nums.size() - 1, right = 1; i >= 0; --i) {
            ans[i] *= right;
            right *=nums[i];
        }
        return ans;
    }
};