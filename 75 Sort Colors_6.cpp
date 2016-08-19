// 75
// Sort Colors
// https://leetcode.com//problems/sort-colors/
class Solution {
public:
    void sortColors(int A[], int n) {
        int i=0,j=0;
        while(j<n)
        {
            if(A[j]==0)
            {
                swap(A[i],A[j]);
                i++;
            }
            j++;
        }
        j=i;
        while(j<n)
        {
            if(A[j]==1)
            {
                swap(A[i],A[j]);
                i++;
            }
            j++;
        }
    }
};