// 8
// String to Integer (atoi)
// https://leetcode.com//problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string str) {
        return atoi(str, 0, 0);
    }
private:
    int atoi(string &s, int i, int x) {
        if (i > 0 && !isdigit(s[i])) return x;
        for(; i < s.length() && s[i] == ' '; ++i) ;
        if (i == s.length()) return x;
        if (s[i] == '+' || s[i] == '-') {
            char sign = s[i];
            for(++i; s[i] == '0'; ++i);
            if (i == s.length() || !isdigit(s[i])) return 0;
            x = (sign == '+' ? 1 : -1) * (s[i] - '0');
            return atoi(s, i + 1, x);
        }
        if (!isdigit(s[i])) return x;
        int d = s[i] - '0';
        if (x < 0 )
            return (INT_MIN + d) / 10 <= x  ? atoi(s, i + 1, x * 10 - d) : INT_MIN;
        return (INT_MAX - d) / 10 >= x ? atoi(s, i + 1, x * 10 + d) : INT_MAX;
        
    }
    
};