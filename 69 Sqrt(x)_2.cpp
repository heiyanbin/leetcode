// 69
// Sqrt(x)
// https://leetcode.com//problems/sqrtx/
class Solution {
public:
    int sqrt(int x) {
        if(x<2) return x;
        int begin=1,end=x/2,last_mid;
        while(begin<=end)
        {
            int mid=(begin+end)/2;
            if(x/mid==mid)
                return mid;
            else if(x/mid<mid)
                end=mid-1;
            else
            {
                begin=mid+1;
                last_mid=mid;
            }
        }
        return end;
    }
};