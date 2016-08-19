// 159
// Longest Substring with At Most Two Distinct Characters
// https://leetcode.com//problems/longest-substring-with-at-most-two-distinct-characters/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.length()<3) return s.length();
        map<char,int> count;
        int l = 0, r=0, maxLen = 1;
        count[s[0]]=1;
        for(;r<s.size();)
        {
            while(r<s.size() && count.size()<3)
            {
                r++;
                count[s[r]]++;
            }
            maxLen= max(maxLen, r-l);
            if(r==s.size()) return maxLen;
            while(count.size()>2)
            {
                count[s[l]]--;
                if(count[s[l]]==0) count.erase(s[l]);
                l++;
            }
        }
        return 0;
    }
};