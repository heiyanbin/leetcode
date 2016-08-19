// 84
// Largest Rectangle in Histogram
// https://leetcode.com//problems/largest-rectangle-in-histogram/
class Solution {
public:
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