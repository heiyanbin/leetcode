// 54
// Spiral Matrix
// https://leetcode.com//problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> output;
        if(matrix.empty()) return output;
        int beginX = 0, endX= matrix[0].size()-1, beginY=0, endY=matrix.size()-1;
        while(true)
        {
            for(int j=beginX;j<=endX;j++) output.push_back(matrix[beginY][j]);
            if(++beginY>endY) break;
            for(int i=beginY;i<=endY;i++) output.push_back(matrix[i][endX]);
            if(beginX>--endX) break;
            for(int j=endX;j>=beginX;j--) output.push_back(matrix[endY][j]);
            if(beginY>--endY) break;
            for(int i=endY;i>=beginY;i--) output.push_back(matrix[i][beginX]);
            if(++beginX>endX) break;
        }
        return output;
    }
};