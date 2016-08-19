// 72
// Edit Distance
// https://leetcode.com//problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m= word1.size(), n = word2.size();
        vector<int> d(n+1),  e(n+1);
        for(int j=0;j<=n;j++)
            d[j]=j;

        for(int i=1;i<=m;i++)
        {
            e[0]=i;
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                    e[j]=d[j-1];
                else
                    e[j]= min(min(e[j-1]+1,d[j]+1), d[j-1]+1);
            }
            d=e;
        }
        return d[n];
    }
};