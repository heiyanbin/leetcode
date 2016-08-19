// 154
// Find Minimum in Rotated Sorted Array II
// https://leetcode.com//problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r - 1 && nums[l] >= nums[r]) {
            int m = l + (r - l) / 2;
            if (nums[m] == nums[l]) ++l;
            else if (nums[m] > nums[l]) l = m + 1;
            else r = m;
        }
        return min(nums[l], nums[r]);
    }
};