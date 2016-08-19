// 260
// Single Number III
// https://leetcode.com//problems/single-number-iii/
#include <numeric>
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor1 = accumulate(nums.begin(), nums.end(), 0, [](int result, int e) {return result ^ e;});
        int i = 0;
        for (; i < 32; ++i) {
            if ((xor1 >> i) & 1)break;
        }
        int a = 0, b = 0;
        for (int e : nums) {
            if ((e >> i) & 1)a ^= e;
            else b ^= e;
        }
        return {a, b};
    }
};