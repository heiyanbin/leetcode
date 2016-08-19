// 50
// Pow(x, n)
// https://leetcode.com//problems/powx-n/
class Solution {
public:
    double pow(double x, int n) {
        if(n<0) return 1.0/power(x, -(long long)n);
        return power(x,n);
    }
    
    double power(double x, long long n)
    {
        double res = 1.0;
        while(n>0) {
            if(n&1) res *= x;
            x *=x;
            n >>= 1;
        }
        return res;
    }
};