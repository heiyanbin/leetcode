// 279
// Perfect Squares
// https://leetcode.com//problems/perfect-squares/
class Solution {
public:
    int numSquares(int n) {
        vector<int> A;
        for (int i = 1; i * i <= n; ++i) A.push_back(i * i);
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = A[i - 1]; j <= n ; ++j) {
                dp[j] = min(dp[j], dp[j - A[i - 1]] + 1);
            }
        }
        return dp[n];
    }
};