// 26
// Remove Duplicates from Sorted Array
// https://leetcode.com//problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(i==0 || A[j]!=A[i-1])
            {
                A[i]=A[j];
                i++;
            }
        }
        return i;
    }
};