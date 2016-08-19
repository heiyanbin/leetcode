// 121
// Best Time to Buy and Sell Stock
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2) return 0;
        
        int maxProfitOfTheDay = 0;
        int maxProfit = 0;
        for(int i=1;i<prices.size();i++)
        {
             maxProfitOfTheDay = max(maxProfitOfTheDay + prices[i]-prices[i-1], 0);
             if(maxProfitOfTheDay > maxProfit)
                maxProfit = maxProfitOfTheDay;
        }
        return maxProfit;
    }
};