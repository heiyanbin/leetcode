// 326
// Power of Three
// https://leetcode.com//problems/power-of-three/
class Solution {
public:
    bool isPowerOfThree(int n) {
        int x = 1;
        for (;;) {
            int step = 3;
            for (; n / step >= x; step *= step) {
                x *= step;
            }
            if (x == n) return true;
            if (step == 3) return false;
        }
    }
};