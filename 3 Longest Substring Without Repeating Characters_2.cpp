// 3
// Longest Substring Without Repeating Characters
// https://leetcode.com//problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2) return s.size();
        vector<int> marked(256,-1);
        int l = 0, r=0, maxLen = 1;
        for(int r=0;r<s.size();r++) { //invariant: s[l,r] has no repeating characters, marked[s[i]] is the last occuring position of s[i]
            if(marked[s[r]]>=l)
                l=marked[s[r]]+1;
            marked[s[r]]=r;
            maxLen= max(maxLen, r-l+1);
        }
        return maxLen;
    }
};