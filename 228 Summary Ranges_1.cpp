// 228
// Summary Ranges
// https://leetcode.com//problems/summary-ranges/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<string> ans;
        for (int start = 0, i = 1; i <= nums.size(); ++i) {
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                string range = to_string(nums[start]);
                if (i - 1 > start) range += "->" + to_string(nums[i - 1]);
                ans.push_back(range);
                start = i;
            }
        }
        return ans;
    }
};