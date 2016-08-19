// 371
// Sum of Two Integers
// https://leetcode.com//problems/sum-of-two-integers/
public class Solution {
    public int getSum(int a, int b) {
        int c = 0;
        for (int i = 0, carry = 0; i < 32; ++i) {
            int x = (a >> i) & 1, y = (b >> i) & 1;
            c = c | ((x ^ y ^ carry) << i);
            if (numberOf1(new int[] {x, y, carry}) >= 2) {
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        
        return c;
    }
    
    private int numberOf1(int[] a) {
        int count = 0;
        for (int x : a) {
            if (x == 1) ++count;
        }
        return count;
    }
}