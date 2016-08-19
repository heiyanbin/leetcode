// 84
// Largest Rectangle in Histogram
// https://leetcode.com//problems/largest-rectangle-in-histogram/
class Solution {
public:    
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;        
        stack<int> stk;        
        height.push_back(0);        
        for(int i=0;i<height.size();)        
        {            
            if(stk.empty()||height[i]>=height[stk.top()])                
                stk.push(i++);            
            else            
            {                
                int tmp= stk.top();                
                stk.pop();                
                maxArea = max(maxArea, height[tmp] * (stk.empty()? i : (i-stk.top()-1)));            
            }        
        }        
        return maxArea;    
    }
};