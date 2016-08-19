// 32
// Longest Valid Parentheses
// https://leetcode.com//problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        int maxLen = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                stack.push_back(i);
            else
            {
                if(!stack.empty() && s[stack.back()]=='(')
                {
                    int last =-1;
                    stack.pop_back();
                    if(!stack.empty())
                        last = stack.back();
                    maxLen = max(maxLen, i-last);
                }
                else
                    stack.push_back(i);
            }
        }
        return maxLen;
    }
};