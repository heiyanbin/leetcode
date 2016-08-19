// 88
// Merge Sorted Array
// https://leetcode.com//problems/merge-sorted-array/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int *C = new int[m+n];
        int i =0, p =0, q=0;
        
        while(p<m && q<n)
        {
            if(A[p]<=B[q])
            {
                C[i]=A[p];
                p++;
            }
            else
            {
                C[i]=B[q];
                q++;
            }
            i++;
        }
        
        while(p<m)
        {
            C[i]=A[p];
            p++;
            i++;
        }
        while(q<n)
        {
            C[i]=B[q];
            q++;
            i++;
        }
        for(i=0;i<m+n;i++)
        {
            A[i]=C[i];
        }
        delete[] C;
    }
};