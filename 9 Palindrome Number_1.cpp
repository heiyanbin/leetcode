// 9
// Palindrome Number
// https://leetcode.com//problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int x1 = x;
        int reverse = 0;
        while(x1>0)
        {
           reverse = reverse * 10 +  x1 %10 ;
           x1 /=10;
        }
        return x==reverse;
    }
};