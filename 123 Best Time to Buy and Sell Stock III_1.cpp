// 123
// Best Time to Buy and Sell Stock III
// https://leetcode.com//problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1) return 0;
        vector<int> d(prices.size());
        for(int i= prices.size()-2, x=0; i>=0;--i) {
            x = max(prices[i+1]-prices[i]+x,0);
            d[i]=max(d[i+1],x);
        }
        int max_profit=0;
        for(int i=0,x=0;i<prices.size();++i) {
            x= i>0 ? max(prices[i]-prices[i-1] + x,0) : 0;
            max_profit = max(max_profit, x + d[i]);
        }
        return max_profit;
    }
};