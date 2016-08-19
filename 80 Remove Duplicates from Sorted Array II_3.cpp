// 80
// Remove Duplicates from Sorted Array II
// https://leetcode.com//problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<3) return n;
        unordered_map<int,int> map;
        int i=0;
        for(int j=0;j<n;j++)
        {
            map[A[j]]++;
            if(map[A[j]]<=2)
            {
                A[i] = A[j];
                i++;
            }
        }
        return i;
    }
};