// 74
// Search a 2D Matrix
// https://leetcode.com//problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0) return false;
        int i=0, j=matrix[0].size()-1;
        while(i<matrix.size() && j>=0)
        {
            if(matrix[i][j]== target)
                return true;
            else if(matrix[i][j]>target)
                j--;
            else
                i++;
        }
        return false;
    }
};