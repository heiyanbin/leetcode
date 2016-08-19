// 75
// Sort Colors
// https://leetcode.com//problems/sort-colors/
class Solution {
public:
    void sortColors(int A[], int n) {
        int i=0,j=0,k=n-1;
        while(j<=k)
        {
            if(A[j]==0)
            {
                swap(A[i],A[j]);
                i++;
                j++;
            }
            else if(A[j]==2)
            {
                swap(A[k],A[j]);
                k--;
            }
            else
                j++;
        }
    }
};