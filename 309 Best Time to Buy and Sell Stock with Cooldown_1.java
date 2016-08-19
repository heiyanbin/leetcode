// 309
// Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock-with-cooldown/
public class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2) return 0;
        int[] f = new int[prices.length], g = new int[prices.length];
        for (int i = 1; i < prices.length; ++i) {
            for (int j = i; j >= 0; --j) {
                f[i] = Math.max(f[i], (j >= 2 ? g[j - 2] : 0) + prices[i] - prices[j]);
            }
            g[i] = f[i] > g[i - 1] ? f[i] : g[i - 1];
        }
        return g[g.length - 1];
    }
}