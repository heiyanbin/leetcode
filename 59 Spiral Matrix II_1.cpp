// 59
// Spiral Matrix II
// https://leetcode.com//problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> output(n,vector<int>(n));
        int begin = 0, end =n-1, num=1;
        while(begin<end)
        {
            for(int j=begin;j<end;j++) output[begin][j]=num++;
            for(int i=begin;i<end;i++) output[i][end]=num++;
            for(int j=end;j>begin;j--) output[end][j]=num++;
            for(int i=end;i>begin;i--) output[i][begin]=num++;
            begin++;end--;
        }
        if(begin==end)
            output[begin][end]=num;
        return output;
    }
};