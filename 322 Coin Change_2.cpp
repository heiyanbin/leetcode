// 322
// Coin Change
// https://leetcode.com//problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> f(coins.size() + 1, vector<int>(amount + 1, -1));
        for (int i = 0; i <= coins.size(); ++i) 
            f[i][0] = 0;
            
        for (int i = 1; i <= coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (f[i - 1][j] < 0 ) {
                    if (j >= coins[i - 1] && f[i][j - coins[i - 1]] >= 0)
                        f[i][j] = f[i][j - coins[i - 1]] + 1;
                    else
                        f[i][j] = -1;
                }
                else {
                    if (j >= coins[i - 1] && f[i][j - coins[i - 1]] >= 0 && f[i][j - coins[i - 1]] + 1 < f[i - 1][j])
                        f[i][j] = f[i][j - coins[i - 1]] + 1;
                    else {
                        f[i][j] = f[i - 1][j];
                    }
                }
            }
            
        }
                
        return f[coins.size()][amount];
    }
};