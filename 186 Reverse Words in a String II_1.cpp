// 186
// Reverse Words in a String II
// https://leetcode.com//problems/reverse-words-in-a-string-ii/
class Solution {
public:
    void reverseWords(string &s) {
        char prev = ' ';
        for (int i = 0, start = 0; i < s.size(); prev = s[i], ++i) {
            if (prev == ' ' && s[i] != ' ') start = i;
            if (s[i] != ' ' && (i + 1 == s.size() || s[i + 1] == ' ')) reverse(s.begin() + start, s.begin() + i + 1);
        }
        reverse(s.begin(), s.end());
    }
};