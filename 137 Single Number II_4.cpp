// 137
// Single Number II
// https://leetcode.com//problems/single-number-ii/
class Solution {
public:
    int singleNumber(int A[], int n) {
        vector<int> sum(32,0);
        for(int k=0; k<n; k++)
        {
            for(int i=0;i<32;i++)
            {
                sum[i]+= (A[k] & (1<<i))>>i;
            }
        }
        int single = 0;
        for(int i=0;i<32;i++)
            single +=  (sum[i]%3)<<i;
        return single;
    }
};