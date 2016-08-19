// 313
// Super Ugly Number
// https://leetcode.com//problems/super-ugly-number/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> ans = {1};
        vector<int> begin(primes.size(), 0);
        for (;;) {
            if (ans.size() == n) return ans.back();
            long long next = -1;
            for (int j = 0; j < primes.size(); ++j) {
                int l = begin[j], r = ans.size() - 1;
                for (; l < r; ) {
                    int m = l + (r - l) / 2;
                    if (ans[m] * primes[j] <= ans.back()) l = m + 1;
                    else r = m;
                }
                begin[j] = l;
                next = next == -1 ? ans[l] * primes[j] : min(next, ans[l] * primes[j]);
            }
            ans.push_back(next);
        }
        
    }
};