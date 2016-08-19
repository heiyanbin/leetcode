// 342
// Power of Four
// https://leetcode.com//problems/power-of-four/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num & (num - 1)) == 0 // power of 2
            && num & 0x55555555;  // the 1 bit is at even position(0, 2, 4..)
    }
};