// 41
// First Missing Positive
// https://leetcode.com//problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(!A||n<1) return 1;
        for(int i=0;i<n;i++)
        {
            while(A[i]!=i+1 && A[i]>0 && A[i]<=n && A[i]!=A[A[i]-1])
            {
                swap(A[i], A[A[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(A[i]!=i+1) return i+1;
        }
        return n+1;
    }
};