// 7
// Reverse Integer
// https://leetcode.com//problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        if(x==0) return 0;
        bool negative = false;
        if(x<0)
        {
            x=-x;
            negative = true;
        }
        int value = 0;
        while(x>0)
        {
            value = 10 * value + x % 10;
            x = x / 10;
        }
        
        return negative ? -value : value;
    }
};