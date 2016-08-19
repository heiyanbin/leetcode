// 258
// Add Digits
// https://leetcode.com//problems/add-digits/
class Solution {
public:
    int addDigits(int num) {
        for (; num > 9; ) {
           int newVal = 0;
           for (; num != 0;) {
               newVal += num % 10;
               num /= 10;
           }
           num = newVal;
        }
        return num;
    }
};