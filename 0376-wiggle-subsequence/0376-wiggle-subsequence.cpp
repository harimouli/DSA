class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        bool isPositive = false;
        for(int i = 0; i<n-1; i++){
            if(nums[i + 1] - nums[i] > 0 && !isPositive){
                isPositive = true;
                dp[i+1] = dp[i] + 1;
            }
            else if(nums[i+1] - nums[i] > 0 && isPositive){
                dp[i + 1] =  dp[i];
            }
            else if(nums[i+1] - nums[i] < 0 && !isPositive){
                isPositive = false;
                if(dp[i] == 0) dp[i+1] = dp[i] + 1;
                else{
                    dp[i+1] = dp[i];
                }
            }
            else if(nums[i+1] - nums[i] < 0 && isPositive){
                dp[i+1] = dp[i]  + 1;
                isPositive = false;
            }
            else{
                dp[i + 1] = dp[i];
            }
        }
        if(n > 1){
            return dp[n-1]  +1;
        }
        else{
            return 1;
        }
    }
};