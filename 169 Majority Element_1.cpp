// 169
// Majority Element
// https://leetcode.com//problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        assert(!nums.empty());
        int x, count = 0;
        for (int e : nums) {
            if (count == 0) {
                x = e;
                count = 1;
            }
            else if (e == x) ++count;
            else --count;
        }
        return x;
    }
};