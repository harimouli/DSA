class Solution {
public:

    int getMinCoinExchange(int ind, vector<int>& coins, int target,  vector<vector<int>> &dp){
            int n = coins.size();
             if(target < 0) return 1e9;   
            if(target == 0) {
                return 0;
            }

            if(ind == n) return 1e9;

            if(dp[ind][target] != -1) return dp[ind][target];

            int ch1 = 1e9;
            
            if(coins[ind] <= target) ch1 = 1 + getMinCoinExchange(ind, coins, target - coins[ind], dp);
            int ch2 = 0 + getMinCoinExchange(ind + 1, coins, target,dp);
           
           return dp[ind][target] = min(ch1, ch2);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = getMinCoinExchange(0 , coins , amount, dp);

        if(ans == 1e9) return -1;
        return ans;

    }
};