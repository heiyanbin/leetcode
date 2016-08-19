// 159
// Longest Substring with At Most Two Distinct Characters
// https://leetcode.com//problems/longest-substring-with-at-most-two-distinct-characters/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.length()<3) return s.length();
        map<char,int> count;
        int maxLen = 0;
        //invariant: s[l,r] has at most 2 ditinct characters, after each iteration
        for(int l=0, r=0;r<s.size();r++) {
            count[s[r]]++;
            while(count.size()>2) {
                count[s[l]]--;
                if(count[s[l]]==0) count.erase(s[l]);
                l++;
            }
            maxLen= max(maxLen, r-l+1);
        }
        return maxLen;
    }
};