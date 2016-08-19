// 29
// Divide Two Integers
// https://leetcode.com//problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {  
        long long a = abs((long long)dividend);  
        long long b = abs((long long)divisor);  
        long long res = 0;  
        while(a >= b)  
        {  
            long long c = b;  
            for(int i = 0; a >= c; i++, c <<=1)  
            {  
                a -= c;  
                res += 1<<i;  
            }  
        }  
        return ((dividend ^ divisor) >> (sizeof(int)*8-1)) ? (-res) : (res);  
    }  
};