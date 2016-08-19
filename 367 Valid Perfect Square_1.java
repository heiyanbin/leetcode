// 367
// Valid Perfect Square
// https://leetcode.com//problems/valid-perfect-square/
public class Solution {
    public boolean isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        
        for (int l = 0, r = num; l <= r;) {
            int m = l + (r - l) / 2;
            if (num / m < m) {
                r = m - 1;
            }
            else if (m * m == num) {
                return true;
            }
            else {
                l = m + 1;
            }
        }
        return false;
    }
}