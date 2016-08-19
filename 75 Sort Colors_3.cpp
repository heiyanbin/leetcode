// 75
// Sort Colors
// https://leetcode.com//problems/sort-colors/
class Solution {
public:
    void sortColors(int A[], int n) {
        int i=-1, j=-1, k=-1;
        for(int p = 0; p < n; p++)
        {
            if(A[p] == 0)
            {
                A[++k]=2;
                A[++j]=1;
                A[++i]=0;
            }
            else if (A[p] == 1)
            {
                A[++k]=2;
                A[++j]=1;
            }
            else if (A[p] == 2)
            {
                A[++k]=2;
            }
        }
    }
};