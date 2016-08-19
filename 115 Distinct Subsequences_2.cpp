// 115
// Distinct Subsequences
// https://leetcode.com//problems/distinct-subsequences/
class Solution {
public:
    int numDistinct(string S, string T) {
        int m= S.size(), n=T.size();
        if (m<n) return 0;
        vector<int>d(n+1,0);
        d[0]=1;
        for(int i=1;i<=m;i++)
            for(int j=n;j>=0;j--)
                d[j] += S[i-1]==T[j-1] ? d[j-1] : 0;
        return d[n];
    }
};