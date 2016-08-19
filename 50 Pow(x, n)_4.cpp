// 50
// Pow(x, n)
// https://leetcode.com//problems/powx-n/
class Solution {
public:
    double pow(double x, int n) {
        if(n<0) return 1.0/power(x,-n);
        return power(x,n);
    }
    
    double power(double x, int n)
    {
        if(n==0) return 1.0;
        double half= pow(x,n/2);
        if((n&1)==0)
            return half*half;
        return half*half*x;
    }
};