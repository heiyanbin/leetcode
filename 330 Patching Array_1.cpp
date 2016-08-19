// 330
// Patching Array
// https://leetcode.com//problems/patching-array/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0;
        long curMax = 0;
        
        for (int i = 0; curMax < n && i < nums.size(); ++i) {
            for (; curMax < n && nums[i] > curMax + 1;) {
                ++count; //adding curMax + 1
                curMax += curMax + 1;
            }
            
            if (curMax >= n) return count;
            
            curMax += nums[i];
        }
        
        for ( ; curMax < n; ) {
            ++count; //adding curMax + 1
            curMax += curMax + 1;
        }
        
        return count;
    }
};