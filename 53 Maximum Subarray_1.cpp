// 53
// Maximum Subarray
// https://leetcode.com//problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n<=0) return 0;
        int maxSum = A[0], maxSumEndWithCurennt = A[0];
        for(int i=1;i<n;i++)
        {
            maxSumEndWithCurennt = max(maxSumEndWithCurennt + A[i], A[i]);
            maxSum = max(maxSum, maxSumEndWithCurennt);
        }
        return maxSum;
    }
};