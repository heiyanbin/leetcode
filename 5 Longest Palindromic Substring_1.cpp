// 5
// Longest Palindromic Substring
// https://leetcode.com//problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 1, start = 0;
        bool f[n][n];
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++)
            {
                f[i][j] = s[i] == s[j] && (j - i < 2 || f[i + 1][j - 1]);
                if (f[i][j] && j - i + 1 > maxLen ){
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};