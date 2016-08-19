// 153
// Find Minimum in Rotated Sorted Array
// https://leetcode.com//problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int> &num) {
        int i= 0, j=num.size()-1;
        while(i<j && num[i]>num[j])
        {
            int m = (i+j)/2;
            if(num[m]>num[j]) //compare with j, because when there left 2 elements, m equals i, we don't want compare with self
                i=m+1;
            else
                j=m;
        }
        return num[i];
    }
};