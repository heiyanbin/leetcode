// 368
// Largest Divisible Subset
// https://leetcode.com//problems/largest-divisible-subset/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(begin(nums), end(nums));
        vector<vector<int>> f(nums.size());
        f[0].push_back(nums[0]);
        
        vector<int> ansV = {nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            int maxNum = 0, maxJ = -1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0) {
                    if (maxNum < f[j].size() + 1) {
                        maxNum = f[j].size() + 1;
                        maxJ = j;
                    }
                }
            }
            if (maxJ != -1) { 
                vector<int> v = f[maxJ];
                v.push_back(nums[i]);
                f[i] = v;
            }
            else {
                f[i] = {nums[i]};
            }
            if (f[i].size() > ansV.size())
                ansV = f[i];
        }
        return ansV;
    }
};