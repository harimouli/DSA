class Solution {
public:

    int getProfit(int ind, vector<int> &prices, int cap, int buy, vector<vector<vector<int>>> &dp){

            int n = prices.size();
            if(cap == 2) {
                return 0;
            }
            if(ind == n) return 0;

            if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int profit = 0;

        if(buy) {

            profit = max(-prices[ind] + getProfit(ind + 1, prices, cap, 0, dp), 0 + getProfit(ind + 1, prices, cap, 1, dp));
        }else{
            profit = max(prices[ind] + getProfit(ind + 1, prices, cap+1, 1, dp), 0 + getProfit(ind + 1, prices, cap, 0, dp));
        }

        return dp[ind][buy][cap] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return getProfit(0, prices, 0, 1, dp);
    }
};