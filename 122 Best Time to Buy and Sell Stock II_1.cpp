// 122
// Best Time to Buy and Sell Stock II
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2) return 0;
        int max_profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>=prices[i-1])
                max_profit += prices[i]-prices[i-1];
        }
        return max_profit;
    }
    
};