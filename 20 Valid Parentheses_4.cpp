// 20
// Valid Parentheses
// https://leetcode.com//problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        int i=0;
        for(int j=0;j<s.size();j++)
        {
            if(!isRight(s[j]))
            {
                s[i]=s[j];
                i++;
            }
            else
            {
                if(i==0 || left(s[j])!=s[i-1])
                    return false;
                i--;
            }
        }
        return i==0;
    }
    bool isRight(char c)
    {
        return c==']' || c==')' || c== '}';
    }
    char left(char c)
    {
        if(c==']') return '[';
        if(c==')') return '(';
        if(c=='}') return '{';
        assert(false);
    }
    
};