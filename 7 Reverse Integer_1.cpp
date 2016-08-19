// 7
// Reverse Integer
// https://leetcode.com//problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        long long v = 0;
        for (; x != 0; x /= 10) {
            v = v * 10 + x % 10;
            if (v > INT_MAX || v < INT_MIN) return 0;
        }
        return v;
    }
};