// 73
// Set Matrix Zeroes
// https://leetcode.com//problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size()<1) return;
        int *row = new int[matrix.size()];
        for(int i=0;i<matrix.size();i++)
            row[i]=0;
        if(matrix[0].size()<1) return;
        int *col = new int[matrix[0].size()];
        for(int i=0;i<matrix[0].size();i++)
            col[i]=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
                if(matrix[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
                if(row[i]==1 ||col[j]==1)
                    matrix[i][j]=0;
        }
    }
};