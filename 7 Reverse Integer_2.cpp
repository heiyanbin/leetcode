// 7
// Reverse Integer
// https://leetcode.com//problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        int value=0;
        while(x)
        {
            value = value*10 + x%10;
            x=x/10;
        }
        return value;
    }
};