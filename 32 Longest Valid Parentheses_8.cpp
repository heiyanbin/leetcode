// 32
// Longest Valid Parentheses
// https://leetcode.com//problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        size_t n = s.size();
        if(n<2) return 0;
        vector<int> d(n,0);
        int maxLen=0;
        d[0]=0;
        if(s[0]=='(' && s[1]==')')
        {
            d[1]=2;
            maxLen=2;
        }
        else
            d[1]=0;
        for(int i=2;i<n;i++)
        {
            if(s[i]=='(')
                d[i] = 0;
            else
            {
                if(s[i-1]=='(')
                    d[i]=2+d[i-2];
                else
                {
                    int k =i-1-d[i-1];
                    if(k>=0 && s[k]=='(')
                        d[i]=2+d[i-1]+ (k-1>=0 ? d[k-1]: 0);
                    else d[i] = 0;
                }
            }
            if(d[i]>maxLen)
                maxLen=d[i];
        }
        return maxLen;
    }
};