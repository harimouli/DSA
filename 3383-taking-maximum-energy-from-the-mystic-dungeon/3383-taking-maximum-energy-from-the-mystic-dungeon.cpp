class Solution {
public:

    int  getAns(int i, vector<int> &energy, int k, vector<int> &dp){
        int n = energy.size();
        if(i >= n) return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        return dp[i] = energy[i] +  getAns(i + k, energy, k, dp);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        
       
        int n = energy.size();
        int ans =INT_MIN;
        vector<int> dp(n, -1);
        for(int i = 0; i<n; i++) {
            ans = max(ans, getAns(i, energy, k, dp));
        }
        return ans;
    }
};