// 72
// Edit Distance
// https://leetcode.com//problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m= word1.size(), n = word2.size();
        if(m==0) return n;
        if(n==0) return m;
        vector<int> d(n+1,INT_MAX),  e(n+1,INT_MAX);
        for(int j=0;j<=n;j++)
            d[j]=j;

        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0)
                    e[j]=i;
                else
                {
                    e[j]= min( min(d[j]+1, e[j-1]+1), d[j-1] + (word1[i-1]==word2[j-1] ? 0 :1));
                }
            }
            d=e;
        }
        return e[n];
    }
};