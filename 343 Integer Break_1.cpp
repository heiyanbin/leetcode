// 343
// Integer Break
// https://leetcode.com//problems/integer-break/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> f(n + 1, 1);
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                f[i] = max(f[i], max(f[j], j) * max(f[i - j], i - j));
            }
        }
        return f[n];
    }
};