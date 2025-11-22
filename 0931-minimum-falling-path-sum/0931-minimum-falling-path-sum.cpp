class Solution {
public:
   /* int getMinFall(int row, int col, vector<vector<int>>&matrix, vector<vector<int>> &dp){

        int n = matrix.size();

        if(col < 0 || col >= n) return INT_MAX;


        
        if(row  == n-1) {
            return matrix[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];

        int bottom = getMinFall(row + 1, col, matrix, dp);
        int bottomLeft = getMinFall(row + 1, col-1, matrix,dp);
        int bottomRight = getMinFall(row +1, col + 1, matrix, dp);

        int value = min(bottom, min(bottomRight, bottomLeft));

        return dp[row][col] =  matrix[row][col] + value;

    } */
    int minFallingPathSum(vector<vector<int>>&matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<int> dp(n, -1);

        for(int col = 0; col<n; col++){
            dp[col] = matrix[0][col];
        }


        for(int row = 1; row<n; row++){
                vector<int> cur(n, -1);
            for(int col = n-1; col >= 0; col--){
                int topLeft =INT_MAX;
                int topRight = INT_MAX;

                int top = dp[col];

                if(col > 0) topLeft =  dp[col-1];

                if(col + 1 < n) topRight =  dp[col+1];
                cur[col] = matrix[row][col] + min(top, min(topRight, topLeft));
            }
            dp = cur;
        }


        for(int col = 0; col < n; col++){
            ans = min(ans, dp[col]);
        }
        return ans;
    }
};