class Solution {
public:

    int getMax(int ind, vector<int> &prices, int buy, int cap, int k, vector<vector<vector<int>>>&dp){
        //base cases 
        int n = prices.size();
        if(ind == n) return 0;

        if(cap == k) return 0;   
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit = 0;

        if(buy) {
            profit = max(-prices[ind] + getMax(ind + 1, prices, 0, cap, k, dp), 0 + getMax(ind +1, prices, 1, cap, k, dp));
        }else{
            profit = max(prices[ind] + getMax(ind + 1, prices, 1, cap + 1, k, dp), 0 + getMax(ind + 1, prices, 0, cap, k, dp));
        }
        return dp[ind][buy][cap] = profit;



    }
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return getMax(0, prices, 1, 0, k, dp);


    }
};