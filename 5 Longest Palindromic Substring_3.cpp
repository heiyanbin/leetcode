// 5
// Longest Palindromic Substring
// https://leetcode.com//problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen=0;
        int maxStart=0;
        size_t n=s.size();
        for(int i=0;i<n;i++)
        {
            int offset= 0;
            while(i-offset>=0 && i+offset<n && s[i-offset]==s[i+offset])
                offset++;
            offset--;
            if(2*offset+1>maxLen)
            {
                maxLen = 2* offset+1;
                maxStart= i-offset;
            }
            
            if(i+1<n && s[i]==s[i+1])
            {
                offset =0;
                while(i-offset>=0 && i+1+offset<n && s[i-offset]==s[i+1+offset])
                    offset++;
                offset--;
                if(2*offset+2>maxLen)
                {
                    maxLen= 2* offset +2;
                    maxStart= i-offset;
                }
            }
        }
        return string(s,maxStart, maxLen);
    }
};