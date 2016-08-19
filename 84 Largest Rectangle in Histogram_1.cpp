// 84
// Largest Rectangle in Histogram
// https://leetcode.com//problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int maxArea = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            while (!s.empty() && height[s.top()] > height[i]) {
                int h = height[s.top()]; s.pop();
                int left = s.empty() ? -1 : s.top();
                maxArea = max(maxArea, h * (i - left - 1));
            }
            s.push(i);
        }
        return maxArea;
    }
};