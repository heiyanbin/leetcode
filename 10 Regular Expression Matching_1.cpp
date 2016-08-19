// 10
// Regular Expression Matching
// https://leetcode.com//problems/regular-expression-matching/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == 0) return *s == 0;
        if (*(p + 1) != '*') 
            return (*s == *p || *p == '.' && *s != 0) && isMatch(s+1, p+1);
        else {
            while (*s == *p || *p == '.' && *s != 0) {
                if (isMatch(s, p + 2)) return true;
                s++;
            }
            return isMatch(s, p + 2);
        }
    }
};