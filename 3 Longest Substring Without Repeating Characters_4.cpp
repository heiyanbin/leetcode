// 3
// Longest Substring Without Repeating Characters
// https://leetcode.com//problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2) return s.size();
        int d=1, maxLen=1;
        for(int i=1;i<s.size();i++)
        {
            int j;
            for(j=i-1;j>=i-d;j--)
            {
                if(s[i]==s[j])
                {
                    break;
                }
            }
            d=i-j;
            maxLen = max(maxLen,d);
        }
        return maxLen;
    }
};