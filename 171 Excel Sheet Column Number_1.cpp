// 171
// Excel Sheet Column Number
// https://leetcode.com//problems/excel-sheet-column-number/
class Solution {
public:
    int titleToNumber(string s) {
        int value = 0;
        for (int i = 0; i < s.size(); value = value * 26 + s[i] - 'A' + 1, ++i) ;
        return value;
    }
};