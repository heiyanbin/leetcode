// 365
// Water and Jug Problem
// https://leetcode.com//problems/water-and-jug-problem/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x < y) return canMeasureWater(y, x, z);
        if (x + y == z || x == z || y == z) return true;
        if (y == 0) return false;
        
        //we get an amount of water only by pouring a larger amount of water into a smaller space
        //a:  water, b: space
        for (int a = x, b = y; ;) {
            if (a == z) return true;

            int c = a - b;
            if (c == z || c <= y && c + x == z || c + y == z) return true;
            
            if (c == 0) return false;
            if (c < y) {
                a = x;
                b = y - c;
            }
            else {
                a = c;
                b = y;
            }
        }
    }
};