// 120
// Triangle
// https://leetcode.com//problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> f(triangle[triangle.size()-1].size());
        int minSum = INT_MAX;
        for(int i=0;i<triangle.size();i++)
        {
            for(int j=triangle[i].size()-1; j>=0; j--)
            {
                if(j==0)
                    f[j] += triangle[i][j];
                else if(j==i)
                    f[j] = f[j-1]+triangle[i][j];
                else
                    f[j] = min(f[j-1],f[j]) + triangle[i][j];
                if(i==triangle.size()-1)
                    minSum = min(minSum, f[j]);
            }
        }
        return minSum;
    }
};