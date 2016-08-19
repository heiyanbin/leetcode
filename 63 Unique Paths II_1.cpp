// 63
// Unique Paths II
// https://leetcode.com//problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m= obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[j]= obstacleGrid[i][j] ? 0 : (j==0 ? 0 : dp[j-1]) + dp[j];
        return dp[n-1];
    }
};