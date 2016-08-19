// 334
// Increasing Triplet Subsequence
// https://leetcode.com//problems/increasing-triplet-subsequence/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> len;
        for (int &x : nums) {
            int i = lower_bound(len.begin(), len.end(), x) - len.begin();
            
            if (i < len.size()) len[i] = x;
            else len.push_back(x);
            
            if (len.size() >= 3) return true;
        }
        
        return false;
    }
};