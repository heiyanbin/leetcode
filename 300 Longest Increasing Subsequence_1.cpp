// 300
// Longest Increasing Subsequence
// https://leetcode.com//problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> last;
        for (int num : nums) {
            auto it = lower_bound(last.begin(), last.end(), num);
            if (it != last.end()) *it = num;
            else last.push_back(num);
        }
        return last.size();
    }
};