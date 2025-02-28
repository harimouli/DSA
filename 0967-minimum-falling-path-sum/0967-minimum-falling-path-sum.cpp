class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));

        for(int j = 0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<n; j++){
                int up = INT_MAX;
                int upLeft = INT_MAX;
                int upRight = INT_MAX;
                up = matrix[i][j] +dp[i-1][j];
                if(j > 0){
                    upLeft = matrix[i][j] + dp[i-1][j-1];
                }
                if(j < n-1){
                    upRight = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min(up, min(upRight, upLeft));
            }
        }
        int ans = INT_MAX;

        for(int i = 0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;

    }
};