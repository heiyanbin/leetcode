// 374
// Guess Number Higher or Lower
// https://leetcode.com//problems/guess-number-higher-or-lower/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        for (int l = 1, r = n; l <= r; ) {
            int m = l + (r - l) / 2;
            int cmp = guess(m);
            if (cmp == 0) return m;
            if (cmp < 0) r = m - 1;
            else l = m + 1;
        }
        return 0;
    }
};