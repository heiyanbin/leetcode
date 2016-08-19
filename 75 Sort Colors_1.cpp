// 75
// Sort Colors
// https://leetcode.com//problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, j = 0, k = nums.size() - 1; j <= k; ++j) {
            if (nums[j] == 0) swap(nums[i++], nums[j]);
            else if (nums[j] == 2) swap(nums[k--], nums[j--]);
        }
    }
};