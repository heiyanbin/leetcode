// 375
// Guess Number Higher or Lower II
// https://leetcode.com//problems/guess-number-higher-or-lower-ii/
class Solution {
public:
    int getMoneyAmount(int n) {
       cache = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
       return f(1, n);
    }
private:
    int f(int i, int j) {
        if (i >= j) return 0;
        if (cache[i][j] != -1) return cache[i][j];
        int x = INT_MAX;
        for (int k = i; k <= j; ++k) {
            x = min(x, k + max(f(i, k - 1), f(k + 1, j)));
        }
        return cache[i][j] = x;
    }
    vector<vector<int>> cache;
};