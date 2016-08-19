// 80
// Remove Duplicates from Sorted Array II
// https://leetcode.com//problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<3) return n;
        int count=1;
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(j!=0 && A[j]==A[j-1])
                count++;
            else 
                count=1;
            if(count<=2)
            {
                A[i] = A[j];
                i++;
            }
        }
        return i;
    }
};