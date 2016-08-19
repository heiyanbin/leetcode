// 20
// Valid Parentheses
// https://leetcode.com//problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        string left="([{", right=")]}";
        for (int j = 0; j < s.size(); j++) {
            if (left.find(s[j]) != string::npos)
                s[i++] = s[j];
            else {
                if (i == 0 || left[right.find(s[j])] != s[i-1])
                    return false;
                i--;
            }
        }
        return i == 0;
    }
};