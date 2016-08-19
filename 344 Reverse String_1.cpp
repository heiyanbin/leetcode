// 344
// Reverse String
// https://leetcode.com//problems/reverse-string/
class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = (int)s.size() - 1; i < j; ++i, --j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
        return s;
    }
};