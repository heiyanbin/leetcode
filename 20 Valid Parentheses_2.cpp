// 20
// Valid Parentheses
// https://leetcode.com//problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        string left= "([{", right=")]}";
        stack<char> stk;
        for(auto c : s)
        {
            if(left.find(c)!=string::npos)
                stk.push(c);
            else
            {
                if(stk.empty() || stk.top()!=left[right.find(c)])
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};