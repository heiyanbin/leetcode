// 229
// Majority Element II
// https://leetcode.com//problems/majority-element-ii/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.empty()) return {};
        if (nums.size() == 1) return {nums[0]};
        int countA = 0, countB = 0, a, b;
        for (int x : nums) {
            if (countA == 0) {
                a = x;
                ++countA;
            }
            else if (x == a) ++countA;
            else if (countB == 0) {
                b = x;
                ++countB;
            }
            else if (x == b) ++countB;
            else {
                --countA;
                --countB;
            }
        }
        countA = 0, countB = 0;
        for (int x : nums) {
            if (x == a) ++countA;
            else if (x == b) ++countB;
        }
        vector<int> ans;
        if (countA > nums.size() / 3) ans.push_back(a);
        if (countB > nums.size() / 3) ans.push_back(b);
        return ans;
    }
};