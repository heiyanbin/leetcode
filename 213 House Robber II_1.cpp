// 213
// House Robber II
// https://leetcode.com//problems/house-robber-ii/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) return max(max(nums[0], nums[1]), nums[2]);
        int a = 0, b = nums[1];
        for (int i = 2; i < nums.size() - 2; i++) {
            int c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        int x = 0, y = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            int z = max(nums[i] + x, y);
            x = y;
            y = z;
        }
        return max(b + nums[nums.size() - 1], y);
    }
};