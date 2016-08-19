// 287
// Find the Duplicate Number
// https://leetcode.com//problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        for (; l < r; ) {
            int m = l + (r - l) / 2;
            int x = accumulate(nums.begin(), nums.end(), 0, [&](int result, int e)->int{if (e >= l && e <= m) ++result; return result;});
            if (x > m - l + 1) r = m;
            else l = m + 1;
        }
        return l;
    }
};