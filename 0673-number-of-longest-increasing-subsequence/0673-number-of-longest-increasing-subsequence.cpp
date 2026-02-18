class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        


        int n = nums.size();
        vector<int> dp(n , 1);
        vector<int> cnt(n, 1);
        int maxLen = 1;
        for(int cur = 1; cur < n; cur++){
            for(int prev = cur - 1; prev >= 0; prev--){


                if(nums[cur] > nums[prev] &&  1 + dp[prev] > dp[cur]){
                        dp[cur] = 1 + dp[prev]; 
                        cnt[cur] = cnt[prev];
                }
                else if(dp[cur] == 1 + dp[prev] && nums[cur] > nums[prev]){
                    cnt[cur] +=  cnt[prev];
                }
              
            }
            if(dp[cur] > maxLen){
                maxLen = dp[cur];
            }
            
        }
       
       
     
      int ans = 0;
      for(int i = 0; i<n; i++){
        if(maxLen == dp[i]) ans += cnt[i];
      }
      return ans;
    }
};