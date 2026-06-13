class Solution {
public:


    int longestIncreasingSub(int ind, int prevInd,vector<int>& nums, vector<vector<int>> &dp){
        
        int n = nums.size();
        if(ind == n) return 0;

        if(dp[ind][prevInd + 1]  != -1) return dp[ind][prevInd + 1];
        int pick = 0;


        if(prevInd == -1 || nums[prevInd] < nums[ind]){
            pick = 1 + longestIncreasingSub(ind + 1, ind, nums, dp);
        }

       int  notPick = longestIncreasingSub(ind  + 1, prevInd, nums, dp);

        return dp[ind][prevInd  + 1] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n, -1));
        return longestIncreasingSub(0, -1,nums, dp);
    }
};