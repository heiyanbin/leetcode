// 72
// Edit Distance
// https://leetcode.com//problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m= word1.size(), n = word2.size();
        if(m==0) return n;
        if(n==0) return m;
        vector<vector<int>> d(m+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 && j==0)
                    d[i][j]= 0;
                else if(i==0)
                    d[i][j]=j;
                else if(j==0)
                    d[i][j]=i;
                else
                {
                    d[i][j]= min( min(d[i-1][j]+1, d[i][j-1]+1), d[i-1][j-1] + (word1[i-1]==word2[j-1] ? 0 :1));
                }
            }
        }
        return d[m][n];
    }
};