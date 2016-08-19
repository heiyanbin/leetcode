// 287
// Find the Duplicate Number
// https://leetcode.com//problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto countInRange = [&](int l, int r)->int {
            int count = 0;  
            for_each(nums.begin(), nums.end(), [&](int e)->void{if (e >= l && e <= r) ++count;});
            return count;
        };
        int l = 1, r = nums.size() - 1;
        for (; l < r; ) {
            int m = l + (r - l) / 2;
            if (countInRange(l, m) > m - l + 1) r = m;
            else l = m + 1;
        }
        return l;
    }
};