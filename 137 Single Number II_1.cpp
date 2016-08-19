// 137
// Single Number II
// https://leetcode.com//problems/single-number-ii/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int j = 0; j < 32; ++j) {//compute each bit of the result number and then add into the result
            int sum = 0;
            for (int e : nums) sum += (e >> j) & 1; // sum of bit j;
            ans |= (sum % 3) << j;
        }
        return ans;
    }
};