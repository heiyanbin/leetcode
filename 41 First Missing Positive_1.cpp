// 41
// First Missing Positive
// https://leetcode.com//problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while(nums[i] > 0 && nums[i] - 1 < nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int i = 0;
        for (; i < nums.size(); ++i) {
            if (nums[i] - 1 != i) return i + 1;
        }
        return i + 1;
    }
};