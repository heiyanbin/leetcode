// 35
// Search Insert Position
// https://leetcode.com//problems/search-insert-position/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i= 0, j= n-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(target==A[mid])
                return mid;
            else if(target<A[mid])
                j=mid-1;
            else
                i=mid+1;
        }
        return i;
    }
};