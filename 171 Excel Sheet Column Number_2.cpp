// 171
// Excel Sheet Column Number
// https://leetcode.com//problems/excel-sheet-column-number/
class Solution {
public:
    int titleToNumber(string s) {
        int value = 0;
        for (int i = s.size() - 1, d = 1; i >= 0; --i) {
            value += (s[i] - 'A' + 1) * d;
            d *= 26;
        }
        return value;
    }
};