// 338
// Counting Bits
// https://leetcode.com//problems/counting-bits/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> f(num + 1);
        f[1] = 1;
        
        for (int i = 2, m = 1; i <= num; ++i) {
            if ((i & (i - 1)) == 0) m = m << 1;
            f[i] = f[i - m] + 1;
        }
        
        return f;
    }
};