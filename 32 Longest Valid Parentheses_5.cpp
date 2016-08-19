// 32
// Longest Valid Parentheses
// https://leetcode.com//problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> mem(s.size(),-1);
        int maxLen=0;
        for(int i=1;i<s.size();i++)
            maxLen = max(maxLen,validLen(s,i,mem));
        return maxLen;
    }
    int validLen(string &s, int i, vector<int> &mem)
    {
        if(i>=0 && mem[i]!=-1) return mem[i];
        if(i<=0 || s[i]=='(')
            return i>=0 ? (mem[i]=0) : 0;
        if(s[i-1]=='(')
            return validLen(s,i-2,mem)+2;
        int len= validLen(s,i-1,mem);
        if(i-len-1>=0 && s[i-len-1]=='(')
            return len+2+validLen(s,i-len-2,mem);
        return mem[i]=0;
    }
};