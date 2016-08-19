// 376
// Wiggle Subsequence
// https://leetcode.com//problems/wiggle-subsequence/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vector<vector<int>> f(nums.size(), vector<int>(2, 1));
        
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j])
                    f[i][1] = max(f[i][1], f[j][0] + 1);
                else if (nums[i] < nums[j])
                    f[i][0] = max(f[i][0], f[j][1] + 1);
            }
            ans = max(f[i][0], f[i][1]);
        }
        return ans;
    }
};