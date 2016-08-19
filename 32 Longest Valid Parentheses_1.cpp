// 32
// Longest Valid Parentheses
// https://leetcode.com//problems/longest-valid-parentheses/
class Solution {
public:
    int longestValidParentheses(string s) {
    	stack<int> stack({-1});
    	int maxLen = 0;
    	for (int i = 0; i < s.size(); ++i) {
    		if (stack.size() > 1 && s[stack.top()] == '(' && s[i] == ')') {
    			stack.pop();
    			maxLen = max(maxLen, i - stack.top());
    		}   
    		else stack.push(i);
    	}
    	return maxLen;
    }
};