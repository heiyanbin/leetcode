// 85
// Maximal Rectangle
// https://leetcode.com//problems/maximal-rectangle/
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n= matrix[0].size();
        if(n==0) return 0;
        vector<int> height(n);
        int maxArea=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    height[j] += 1;
                else
                    height[j]=0;
            }
            int area = largestRectangleArea(height);
            if(area>maxArea)
                maxArea = area;
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        for(int i=0;i<height.size();i++)
        {
            if(i+1<height.size() && height[i+1]>=height[i])
                continue;
            int h= height[i];
            for(int j=i;j>=0;j--)
            {
                if(height[j]<h)
                    h= height[j];
                int area = (i-j+1)*h;
                if(area>maxArea)
                    maxArea = area;
            }
        }
        return maxArea;
    }
};