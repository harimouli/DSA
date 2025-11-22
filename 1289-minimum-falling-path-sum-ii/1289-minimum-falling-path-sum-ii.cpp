class Solution {
public:

    /*int getMinFall(int row, int col, vector<vector<int>> &grid, vector<vector<int>>&dp){
        int n = grid.size();

        if(col < 0 || col >=n) return INT_MAX;
        if(row == n-1) return grid[row][col];

        if(dp[row][col] != -1) return dp[row][col];

        int best = INT_MAX;
        for(int next = 0; next<n; next++){
            if(next == col) continue;
            if(dp[row][next] != -1) return dp[row][next];
            best = min(best, getMinFall(row+1, next , grid, dp));
        }
 
        return dp[row][col] =  grid[row][col]  + best;

    } */
    int minFallingPathSum(vector<vector<int>>& grid) {
        


        int ans = INT_MAX;
        int n = grid.size();
       

        vector<int>dp(n, -1);

        for(int col = 0; col<n; col++) {
            dp[col] = grid[0][col];
        }

       
        for(int row = 1; row<n; row++){
            
             vector<int> newDP(n, INT_MAX);
            for(int col = 0; col<n; col++){
                int mini = INT_MAX;
               
               for(int next = 0; next<n; next++){
                    if(col == next) continue;
                    mini = min(mini, dp[next]);
               }
                 newDP[col] =  grid[row][col] + mini;
            }
            dp = newDP;
            
        }


        for(int i = 0; i<n; i++){
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};