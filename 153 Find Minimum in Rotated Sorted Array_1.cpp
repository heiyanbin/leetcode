// 153
// Find Minimum in Rotated Sorted Array
// https://leetcode.com//problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (l < r - 1 && num[l] > num[r]) {
            int m = l + (r - l) / 2;
            if (num[m] > num[l]) l = m + 1;
            else r = m;
        }
        return min(num[l], num[r]);
    }
};