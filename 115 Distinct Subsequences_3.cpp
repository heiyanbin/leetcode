// 115
// Distinct Subsequences
// https://leetcode.com//problems/distinct-subsequences/
class Solution {
public:
    int numDistinct(string S, string T) {
        int n= S.size(), m=T.size();
        if (n<m) return 0;
        vector<vector<int>>d(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
            d[i][0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                d[i][j]= d[i-1][j] + (S[i-1]==T[j-1] ? d[i-1][j-1] : 0);
            }
        }
        return d[n][m];
    }
};