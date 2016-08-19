// 190
// Reverse Bits
// https://leetcode.com//problems/reverse-bits/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < sizeof(n) * 8; n >>= 1, ++i) 
            ans = (ans << 1) + (n & 1);
        return ans;
    }
};