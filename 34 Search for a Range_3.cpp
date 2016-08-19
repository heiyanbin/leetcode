// 34
// Search for a Range
// https://leetcode.com//problems/search-for-a-range/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> output(2,-1);
        int i = 0,j=n-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(target<A[mid])
                j=mid-1;
            else if(target>A[mid])
                i=mid+1;
            else
            {
                int k=mid;
                while(A[k]==target && k>=0)
                    k--;
                output[0]=k+1;
                k=mid;
                while(A[k]==target && k<n)
                    k++;
                output[1]=k-1;
                break;
            }
        }
        return output;
    }
};