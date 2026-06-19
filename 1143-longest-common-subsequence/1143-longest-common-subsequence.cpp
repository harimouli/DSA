class Solution {
public:
    int maxCommSubsequence(int ind1, int ind2, string& text1, string& text2,
                           vector<vector<int>>& dp) {
        int m = text1.size();
        int n = text2.size();

        for (int ind1 = m-1; ind1 >= 0; ind1--) {

            for (int ind2 = n-1; ind2 >= 0; ind2--) {

                if (text1[ind1] == text2[ind2]) {
                    dp[ind1][ind2] = 1 + dp[ind1 + 1][ind2 +  1];
                } else {
                    int f1 = dp[ind1 + 1][ind2];

                    int f2 = dp[ind1][ind2 + 1];

                    dp[ind1][ind2] = max(f1, f2);
                }
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

      

        return maxCommSubsequence(0, 0, text1, text2, dp);
    }
};