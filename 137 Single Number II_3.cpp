// 137
// Single Number II
// https://leetcode.com//problems/single-number-ii/
class Solution {
public:
    int singleNumber(int A[], int n) {
        vector<int> bitSum(32);
        for(int i=0;i<n;++i)
            for(int j=0;j<32;++j)
                bitSum[j] += (A[i]>>j)&1;
        int x=0;
        for(int j=0;j<32;++j)
            x |= (bitSum[j]%3)<<j;
        return x;
    }
};