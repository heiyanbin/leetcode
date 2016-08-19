// 31
// Next Permutation
// https://leetcode.com//problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<=1) return;
        
        int i=num.size()-1;
        while(i>=0 && num[i]<=num[i-1])
            i--;
        if(i<0)
        {
            reverse(num,0,num.size()-1);
            return;
        }
        else
        {
            for(int j=num.size()-1;j>=i;j--)
            {
                if(num[j]>num[i-1])
                {
                    swap(num[i-1],num[j]);
                    reverse(num, i, num.size()-1);
                    return;
                }
            }
        }
    }
    
    void reverse(vector<int> &v, int start, int end)
    {
        if(v.size()<=1) return;
        if(start<0) start=0;
        if(end>=v.size()) end = v.size()-1;
        while(start<end)
        {
            swap(v[start], v[end]);
            start++; end--;
        }
    }
};