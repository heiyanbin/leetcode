// 34
// Search for a Range
// https://leetcode.com//problems/search-for-a-range/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = lower_bound1(A,n,target);
        int upper = upper_bound1(A,n,target);
        if(lower==n||A[lower]!=target) return vector<int>{-1,-1};
        return vector<int>{lower,upper};
    }
    int lower_bound1(int A[], int n, int target)
    {
        int i=0,j=n-1;
        while(i<=j)
        {
            int mid= i+(j-i)/2;
            if(target<=A[mid]) 
                j=mid-1;
            else 
                i=mid+1;
        }
        return i;
    }
    int upper_bound1(int A[], int n, int target)
    {
        int i=0,j=n-1;
        while(i<=j)
        {
            int mid= i+(j-i)/2;
            if(target<A[mid]) 
                j=mid-1;
            else 
                i=mid+1;
        }
        return j;
    }
};