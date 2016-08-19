// 42
// Trapping Rain Water
// https://leetcode.com//problems/trapping-rain-water/
class Solution {
public:
    int trap(int A[], int n) {
        if(n<2) return 0;
        vector<int> max_right(n,0);
        for(int i=n-2;i>=0;i--)
            max_right[i]=max(max_right[i+1],A[i+1]);

        int max_left = 0, sum = 0;
        for(int i=1;i<n;i++)
        {
            max_left = max(max_left, A[i-1]);
            int height = min(max_left, max_right[i]);
            if(height>A[i])
                sum += height-A[i];
        }
        return sum;
    }
};