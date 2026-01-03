class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        if (totalSum % 2 == 1)
            return false;
        int k = totalSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if(nums[0] <= k)    dp[0][nums[0]] = true;

        for (int index = 1; index < n; index++) {
            for (int target = 0; target <= k; target++) {

                bool notPick = dp[index - 1][target];
                bool pick = false;
                if (nums[index] <= target) {
                    pick = dp[index - 1][target - nums[index]];
                                              
                }
                dp[index][target] = pick || notPick;
            }
        }
        return dp[n-1][k];
    }
};