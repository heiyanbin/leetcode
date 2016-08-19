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
            if(!stack.empty() && s[stack.back()]=='(' && s[i]==')')
            {
                stack.pop_back();
                maxLen = max(maxLen, i-(stack.empty()? -1 : stack.back()));
            }
            else
                stack.push_back(i);
        }
        return maxLen;
    }
};