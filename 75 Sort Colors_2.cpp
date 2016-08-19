// 75
// Sort Colors
// https://leetcode.com//problems/sort-colors/
class Solution {
public:
    void sortColors(int A[], int n) {
        for(int i=0, j=0, k=n-1; j<=k;)
        {
            if(A[j]==0)
                swap(A[i++],A[j++]);
            else if(A[j]==1)
                j++;
            else
                swap(A[k--],A[j]);
        }
    }
};