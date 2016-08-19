// 136
// Single Number
// https://leetcode.com//problems/single-number/
class Solution {
public:
    int singleNumber(int A[], int n) {
        assert (A && n>0);
        int num =0;
        for(int i=0;i<n;i++ )
        {
            num = num ^ A[i];
        }
        return num;
    }
};