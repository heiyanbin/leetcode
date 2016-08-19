// 33
// Search in Rotated Sorted Array
// https://leetcode.com//problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(int A[], int n, int target) {
        int i=0, j=n-1;
        while(i<=j)
        {
            int mid= (i+j)/2;
            if(A[mid]==target)
                return mid;
            if(A[mid]>=A[i])
            {
                if(target<A[mid])
                {
                    if(target==A[i]) return i;
                    else if(target<A[i])
                    {
                        i=mid+1;
                    }
                    else
                        j=mid-1;
                }
                else
                {
                    i=mid+1;
                }
            }
            else
            {
                if(target<A[mid])
                {
                    j=mid-1;
                }
                else
                {
                    if(target==A[j]) return j;
                    else if(target<A[j]) i=mid+1;
                    else j=mid-1;
                }
            }
        }
        return -1;
    }
};