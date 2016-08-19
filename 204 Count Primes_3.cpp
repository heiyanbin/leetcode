// 204
// Count Primes
// https://leetcode.com//problems/count-primes/
class Solution {
public:
    int countPrimes(int n) {
		vector<bool> marked(n, false);
		int count = 0;
		for (int i = 2; i < n; ++i) {
			if (!marked[i]) {
				++count;
				for (auto j = (long long)i * i; j < n; j += i) marked[j] = true;
			}
		}
		return count;
	}
};