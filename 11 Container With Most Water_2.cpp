// 11
// Container With Most Water
// https://leetcode.com//problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.size()<2) return 0;
        int i=0, j=height.size()-1;
        int maxArea = min(height[i],height[j])*(j-i);
        while(i<j)
        {
            if(height[i]<height[j])
                i++;
            else
                j--;
            int area = min(height[i],height[j])*(j-i);
            if(area >maxArea)
                maxArea = area;
        }
        return maxArea;
    }
};