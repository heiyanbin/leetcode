// 80
// Remove Duplicates from Sorted Array II
// https://leetcode.com//problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<3) return n;
        int i=2;
        for(int j=2;j<n;j++)
        {
            if(A[j]!=A[i-2])
            {
                A[i] = A[j];
                i++;
            }
        }
        return i;
    }
};