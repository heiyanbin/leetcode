// 377
// Combination Sum IV
// https://leetcode.com//problems/combination-sum-iv/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> f(target + 1);
        f[0] = 1;
        for (int j = 1; j <= target; ++j) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= j) {
                    f[j] +=  f[j - nums[i]];
                }
            }
        }
        return f[target];
    }
};