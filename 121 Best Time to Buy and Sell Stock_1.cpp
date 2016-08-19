// 121
// Best Time to Buy and Sell Stock
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2) return 0;
        
        int buy = prices[0];
        int max_profit =0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-buy>max_profit)
                max_profit=prices[i]-buy;
            if(prices[i]<buy)
                buy=prices[i];
        }
        return max_profit;
    }
};