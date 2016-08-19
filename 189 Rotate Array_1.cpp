// 189
// Rotate Array
// https://leetcode.com//problems/rotate-array/
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        reverse(nums, nums + n - k);
        reverse(nums + n - k, nums + n);
        reverse(nums, nums + n);
    }
};