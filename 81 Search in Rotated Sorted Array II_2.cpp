// 81
// Search in Rotated Sorted Array II
// https://leetcode.com//problems/search-in-rotated-sorted-array-ii/
class Solution {
public:
    bool search(int A[], int n, int target) {
        int i=0,j=n-1;
        while(i<=j)
        {
            int mid= (i+j)/2;
            if(A[mid]==target)
                return true;
            if(A[i]==A[mid])
                i++;
            else if(A[i]<A[mid])
            {
                if(target<A[mid] && target>=A[i])
                    j=mid-1;
                else
                    i=mid+1;
            }
            else
            {
                if(target>A[mid] && target<=A[j])
                    i=mid+1;
                else
                    j=mid-1;
            }
        }
        return false;
    }
};