// 263
// Ugly Number
// https://leetcode.com//problems/ugly-number/
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        const int a[] = {2, 3, 5};
        for (int factor : a) {
            while (num % factor == 0) {
                num /= factor;
            }
        }
        return num == 1;
    }
};