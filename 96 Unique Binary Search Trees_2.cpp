// 96
// Unique Binary Search Trees
// https://leetcode.com//problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++)
            dp[i]= dp[i-1]*(4*i-2)/(i+1);
        return dp[n];
    }
};