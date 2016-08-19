// 204
// Count Primes
// https://leetcode.com//problems/count-primes/
public class Solution {
    public int countPrimes(int n) {
        boolean[] marked = new boolean[n];
		int count = 0;
		for (int i = 2; i < n; ++i) {
			if (!marked[i]) {
				++count;
				for (long j = (long)i * i; j < n && j > 0; j += i) marked[(int)j] = true;
			}
		}
		return count;
    }
}