class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int total = 0;
        for (int x : nums)
            total += x;

        if ((total - target) % 2 != 0) return 0;

        if(total - target <0) return 0;

        int s2 = (total - target) / 2;

        vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

        if (nums[0] == 0) {
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
            if (nums[0] <= s2) {
                dp[0][nums[0]] = 1;
            }
        }

        for (int index = 1; index < n; index++) {

            for (int val = 0; val <= s2; val++) {
                int pick = 0;
                if (nums[index] <= val) {
                    pick = dp[index - 1][val - nums[index]];
                }
                int notPick = dp[index - 1][val];

                dp[index][val] = (pick + notPick);
            }
        }

        return dp[n-1][s2];
    }
};