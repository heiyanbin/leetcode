// 132
// Palindrome Partitioning II
// https://leetcode.com//problems/palindrome-partitioning-ii/
class Solution {
public:
    int minCut(string s) {
        vector<int> cuts(s.size());
        for (int i = 0; i < s.size(); ++i)
            cuts[i] = i;
        for (int i = 0; i < s.size(); ++i ) {
            for (int k = 0; i - k >= 0 && i + k < s.size() && s[i - k] == s[i + k]; ++k)
                cuts[i + k] = min(cuts[i + k], i - k > 0 ? cuts[i - k - 1] + 1 : 0);
            for (int k = 0; i - k >= 0 && i + 1 + k < s.size() && s[i - k] == s[i + 1 + k]; ++k)
                cuts[i + 1 + k] = min(cuts[i + 1 + k], i - k > 0 ? cuts[i - k - 1] + 1: 0);
        }
        return cuts.back();
    }
};