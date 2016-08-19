// 97
// Interleaving String
// https://leetcode.com//problems/interleaving-string/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t n1 = s1.size(), n2= s2.size();
        if(n1+n2!=s3.size())
            return false;
        vector<vector<bool>> f(n1+1, vector<bool>(n2+1,false));
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                f[i][j]= (i==0 && j==0) || (i!=0 && f[i-1][j] && s1[i-1]==s3[i+j-1]) || (j!=0 && f[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return f[n1][n2];
    }
};
