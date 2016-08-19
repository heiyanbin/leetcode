// 367
// Valid Perfect Square
// https://leetcode.com//problems/valid-perfect-square/
public class Solution {
    public boolean isPerfectSquare(int num) {
        if (num == 0) return true;
        
        for (int cur = 0; ;) {
            int step = 1;
            for (; cur + step <= num / (cur + step); step = 2 * step) {
                cur += step;
                if (cur * cur == num) return true;
            }
            if (step == 1) return false;
        }
    }
}