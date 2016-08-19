// 268
// Missing Number
// https://leetcode.com//problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while(nums[i] < nums.size() && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
        }
        int i = 0;
        for (; i < nums.size() && nums[i] == i; ++i) ;
        return i;
    }
};