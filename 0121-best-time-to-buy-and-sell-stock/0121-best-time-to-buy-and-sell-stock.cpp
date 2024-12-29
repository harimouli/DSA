class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        int maxProfit = 0;
        int stock = prices[0];
        int profit;
        for(int i = 1; i<n; i++){
            profit = prices[i] - stock;
            maxProfit = max(profit, maxProfit);
            stock = min(stock, prices[i]);
        }
        return maxProfit;
    }
};