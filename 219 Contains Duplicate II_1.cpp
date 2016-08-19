// 219
// Contains Duplicate II
// https://leetcode.com//problems/contains-duplicate-ii/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = m.find(nums[i]);
            if (it == m.end()) m[nums[i]] = i;
            else if (i - it->second <= k) return true;
            else it -> second = i;
        }
        return false;
    }
};