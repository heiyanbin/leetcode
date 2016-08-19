// 120
// Triangle
// https://leetcode.com//problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if(n==0) return 0;
        if(n==1) return triangle[0][0];
        vector<int> f(n);
        f[0]= triangle[0][0];
        int minSum = INT_MAX;
        for(int i=1;i<n;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(j==0)
                    f[j] = f[j] + triangle[i][j];
                else if(j==i)
                    f[j] = f[j-1] + triangle[i][j];
                else
                    f[j] = min(f[j-1],f[j]) + triangle[i][j];
                if((i==n-1) && f[j] < minSum)
                    minSum= f[j];
            }
        }
        return minSum;
    }
};