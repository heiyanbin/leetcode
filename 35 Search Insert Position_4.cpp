// 35
// Search Insert Position
// https://leetcode.com//problems/search-insert-position/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i= 0, j= n-1, mid=0;
        int lastCompare = 0;
        while(i<=j)
        {
            mid = (i+j)/2;
            if(target==A[mid])
                return mid;
            else if(target<A[mid])
            {
                j=mid-1;
                lastCompare = 0;
            }
            else
            {
                i=mid+1;
                lastCompare = 1;
            }
        }
        return lastCompare ==0 ? mid : mid +1;
    }
};