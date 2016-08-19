// 55
// Jump Game
// https://leetcode.com//problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, reach = 0; i <= reach; ++i) {
            reach = max(reach, i + nums[i]);
            if (reach >= nums.size() - 1) return true;
        }
        return false;
    }
};