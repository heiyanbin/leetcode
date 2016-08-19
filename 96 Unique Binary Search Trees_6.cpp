// 96
// Unique Binary Search Trees
// https://leetcode.com//problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        if(n<0) return 0;
        if(n<=2) return n;
        int *dp = new int[n+1];
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            int sum=0;
            for(int k=1;k<i-1;k++)
            {
                sum += dp[k]*dp[i-1-k];
            }
            dp[i]=2*dp[i-1] + sum;
        }
        int num = dp[n];
        delete[] dp;
        return num;
    }
};