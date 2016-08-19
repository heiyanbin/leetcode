// 154
// Find Minimum in Rotated Sorted Array II
// https://leetcode.com//problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int> &num) {
        int i=0,j=num.size()-1;
        while(i<j && num[i]>=num[j])//invariant: the min is within [i,j] before and after the loop.
        {
            int mid= (i+j)/2;
            if(num[mid]>num[i])
                i=mid+1;
            else if(num[mid]<num[j])
                j=mid;
            else //num[mid]<=num[i] && num[mid]>=num[j], actually this is num[i]==num[mid]==num[j]
                i++;
        }
        return num[i]; 
        //when loop exit:1) min is in [i,j]; 2) either i==j or num[i]<num[j]
        //either case in 2) the min is sure to be num[i];
    }
};