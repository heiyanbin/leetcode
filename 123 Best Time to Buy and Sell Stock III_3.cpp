// 123
// Best Time to Buy and Sell Stock III
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n= prices.size();
        if(n<2) return 0;
        if(n==2) return max(prices[1]-prices[0],0);
        
        int *d = new int[n];
        d[0]=0;
        int max_profitSellInTheDay =0;
        for(int i=1;i<n;i++)
        {
            max_profitSellInTheDay = max(max_profitSellInTheDay+prices[i]-prices[i-1], 0);
            d[i]=max(d[i-1],max_profitSellInTheDay);
        }
        
        int *d2 = new int[n];
        d2[0] =0;
        int max_profitBuyInTheDay =0;
        for(int i=1;i<n;i++)
        {
            int j= n-1-i;
            max_profitBuyInTheDay=max(max_profitBuyInTheDay + prices[j+1]-prices[j], 0);
            d2[i]= max( d2[i-1], max_profitBuyInTheDay);
        }
        
        int max_profit=d[n-1];
        for(int i=1;i<n-1;i++)
        {
            if(d[i]+d2[n-i-2]> max_profit)
                max_profit = d[i]+d2[n-2-i];
        }
        delete[] d;
        delete[] d2;
        return max_profit;
    }
};