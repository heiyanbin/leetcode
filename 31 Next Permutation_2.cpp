// 31
// Next Permutation
// https://leetcode.com//problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n= num.size();
        if(n<=1) return;
        int i=n-2;
        while(i>=0 && num[i]>=num[i+1])
            i--;
        if(i<0) 
            reverse(num.begin(),num.end());
        else
        {
            for(int j=n-1;j>i;j--)
            {
                if(num[j]>num[i])
                {
                    swap(num[i],num[j]);
                    reverse(num.begin()+i+1,num.end());
                    return;
                }
            }
        }
    }
};