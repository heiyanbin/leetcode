// 342
// Power of Four
// https://leetcode.com//problems/power-of-four/
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num & (num - 1)) == 0 // power of 2
            && (num - 1) % 3 == 0; //4 * 4 * 4... * 4, this must be true;
    }
};