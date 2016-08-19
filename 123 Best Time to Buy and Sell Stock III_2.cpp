// 123
// Best Time to Buy and Sell Stock III
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n= prices.size();
        if(n<2) return 0;
        if(n==2) return max(prices[1]-prices[0],0);
        
        vector<int> d(n,0);
        int max_profitSellInTheDay =0;
        for(int i=1;i<n;i++)
        {
            max_profitSellInTheDay = max(max_profitSellInTheDay+prices[i]-prices[i-1], 0);
            d[i]=max(d[i-1],max_profitSellInTheDay);
        }
        
        int max_profitBuyInTheDay =0;
        int max_profit=d[n-1];
        for(int i=n-2;i>=0;i--)
        {
            max_profitBuyInTheDay=max(max_profitBuyInTheDay + prices[i+1]-prices[i], 0);
            max_profit = max(max_profit,max_profitBuyInTheDay+d[i]);
        }
        return max_profit;
    }
};