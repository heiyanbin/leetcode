// 153
// Find Minimum in Rotated Sorted Array
// https://leetcode.com//problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int> &num) {
        int i= 0, j=num.size()-1;
        while(i<j-1)
        {
            int mid = (i+j)/2;
            if(num[mid]>num[i])
            {
                if(num[mid]<num[j])
                    return num[i];
                i=mid+1;
            }
            else
                j=mid;
        }
        return min(num[i],num[j]);
    }
};