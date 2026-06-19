class Solution {
public:

    

    int maxCommSubsequence(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
        int m = text1.size();
        int n = text2.size();
        if(ind1 == m || ind2 == n) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2]){
            return 1 + maxCommSubsequence(ind1 + 1, ind2 + 1, text1, text2, dp);
        }
        int f1 = 0;
        int f2 = 0;
        if( ind1 + 1 < m) f1 = maxCommSubsequence(ind1 + 1, ind2, text1, text2, dp);
        if(ind2 + 1 < n) f2 = maxCommSubsequence(ind1, ind2 +  1, text1, text2, dp);

        return dp[ind1][ind2] = max(f1, f2); 
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return maxCommSubsequence(0, 0, text1, text2, dp);
    }
};