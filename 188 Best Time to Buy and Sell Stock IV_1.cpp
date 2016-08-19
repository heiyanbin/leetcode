// 188
// Best Time to Buy and Sell Stock IV
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
		if (k < 1 || prices.size() <= 1) return 0;
		if (k >= prices.size() / 2) {
			int sum = 0;
			for (int i = 1; i < prices.size(); i++)
			    if (prices[i] > prices[i - 1]) sum += prices[i] - prices[i - 1];
			return sum;
		}
		vector<vector<int>> f(2, vector<int>(k + 1)), g(2, vector<int>(k + 1));
		for (int i = 1; i < prices.size(); i++) {
			for (int j = 1; j <= k; j++) {
				f[i % 2][j] = max(f[(i - 1) % 2][j], g[(i - 1) % 2][j - 1]) + prices[i] - prices[i - 1];
				g[i % 2][j] = max(f[i % 2][j], g[(i - 1) % 2][j]);
			}
		}
		return g[(prices.size() - 1) % 2][k];
	}
};