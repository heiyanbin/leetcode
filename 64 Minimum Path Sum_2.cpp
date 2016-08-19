// 64
// Minimum Path Sum
// https://leetcode.com//problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        
        if(grid.size()==0|| grid[0].size()==0) return 0;
        int *d = new int[grid[0].size()];
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(i==0 &&j==0) 
                    d[j]=grid[i][j];
                else if(i==0)
                    d[j] = d[j-1] + grid[i][j];
                else if(j==0)
                    d[j] = d[j] + grid[i][j];
                else
                    d[j] = min (d[j-1],d[j]) + grid[i][j];
            }
        }
        return d[grid[0].size()-1];
    }
    
};