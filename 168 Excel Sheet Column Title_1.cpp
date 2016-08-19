// 168
// Excel Sheet Column Title
// https://leetcode.com//problems/excel-sheet-column-title/
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        for (; n > 0; s.push_back((n -1) % 26  + 'A'), n = (n - 1) / 26 ) ;
        return string(s.rbegin(), s.rend());
    }
};