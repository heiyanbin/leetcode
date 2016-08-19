// 172
// Factorial Trailing Zeroes
// https://leetcode.com//problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0, f = 5;
        while (f <= n) {
            for (int i = f; (i % 5) == 0; num += 1, i /= 5) ;
            f += 5;
        }
        return num;
    }
};