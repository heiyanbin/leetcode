// 73
// Set Matrix Zeroes
// https://leetcode.com//problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.size()<1) return;
        vector<bool> row(matrix.size(),false);
        if(matrix[0].size()<1) return;
        vector<bool> col(matrix[0].size(),false);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
                if(matrix[i][j]==0)
                {
                    row[i]=true;
                    col[j]=true;
                }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
                if(row[i] ||col[j])
                    matrix[i][j]=0;
        }
    }
};