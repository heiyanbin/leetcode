// 26
// Remove Duplicates from Sorted Array
// https://leetcode.com//problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        map<int,int> mp;
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(mp.count(A[j])==0)
            {
                A[i]=A[j];
                mp[A[j]]++;
                i++;
            }
        }
        return i;
    }
};