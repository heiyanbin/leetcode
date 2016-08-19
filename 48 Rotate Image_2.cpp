// 48
// Rotate Image
// https://leetcode.com//problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n= matrix.size();
        if(n<2) return;
        for(int k=0;k<n/2;k++)
        {
            for(int i=k;i<n-k-1;i++)
            {
                int temp = matrix[k][i];
                matrix[k][i]=matrix[n-1-i][k];
                matrix[n-1-i][k]=matrix[n-k-1][n-1-i];
                matrix[n-k-1][n-1-i]=matrix[i][n-1-k];
                matrix[i][n-1-k]=temp;
            }
        }
    }
};