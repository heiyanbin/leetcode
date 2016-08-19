// 172
// Factorial Trailing Zeroes
// https://leetcode.com//problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0;
        for (int i = 5; i <= n; num += n / i, i *= 5) ;
        return num;
    }
};