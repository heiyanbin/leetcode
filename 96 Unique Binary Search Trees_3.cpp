// 96
// Unique Binary Search Trees
// https://leetcode.com//problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
            for(int k=1;k<=i;k++) //iterate the case k(1..i) as the root
                dp[i] += dp[k-1]*dp[i-k];
        return dp[n];
    }
};