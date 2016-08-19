// 137
// Single Number II
// https://leetcode.com//problems/single-number-ii/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> B(32);
        int res = 0;
        for (int j = 0; j < 32; ++j) {//compute each bit of the result number and then add into the result
            for (int i = 0; i < nums.size(); ++i) B[j] += (nums[i] >> j) & 1; // B[j]: sum of bit j;
            res |= (B[j] % 3) << j;
        }
        return res;
    }
};