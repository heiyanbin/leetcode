// 63
// Unique Paths II
// https://leetcode.com//problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n= obstacleGrid.size();
        assert(n>0);
        int m = obstacleGrid[0].size();
        assert(m>0);
        int *dp = new int[m];
        for(int j=0;j<m;j++)
        {
            if(obstacleGrid[0][j]==1)
            {    
                dp[j]=0;
                for(int k=j+1;k<m;k++)
                {
                    dp[k]=0;
                }
                break;
            }
            else
                dp[j]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    if(j!=0)
                        dp[j]=dp[j-1]+dp[j];
                }
                else
                    dp[j]=0;
            }
        }
        return dp[m-1];
        
    }
};