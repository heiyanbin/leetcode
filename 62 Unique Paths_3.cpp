// 62
// Unique Paths
// https://leetcode.com//problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        assert(m>0 && n>0);
        int *dp = new int[n+1];
        for(int j=1;j<=n;j++)
        {
            dp[j]=1;
        }
        for(int i=2;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==1)
                    dp[j]=1;
                else
                    dp[j]=dp[j-1]+dp[j];
            }
        }
        int ret = dp[n];
        delete[] dp;
        return ret;
    }
};