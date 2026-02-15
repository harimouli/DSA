class Solution {
public:

    int longestSub(int index, int prevIndex, vector<vector<int>> &dp, vector<int> &nums){
        int n = nums.size();

        if(index == n) return 0;

        if(dp[index][prevIndex + 1] != -1) return dp[index][prevIndex + 1];
        int notPick = longestSub(index + 1, prevIndex, dp, nums);
        int pick = 0;

        if(prevIndex == -1  || nums[index] > nums[prevIndex]){
            pick = 1 + longestSub(index + 1, index, dp, nums);
        }

        return dp[index][prevIndex + 1] = max(pick , notPick);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return longestSub(0, -1, dp, nums);
    }
};