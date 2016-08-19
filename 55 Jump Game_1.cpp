// 55
// Jump Game
// https://leetcode.com//problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nearestCanReach = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if  (i + nums[i] >= nearestCanReach) nearestCanReach = i;
        }
        return nearestCanReach == 0;
    }
};