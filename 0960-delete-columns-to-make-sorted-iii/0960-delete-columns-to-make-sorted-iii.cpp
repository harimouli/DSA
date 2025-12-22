class Solution {
public:
    bool  isValid(int i , int prev, vector<string>&strs){
        int n = strs.size();
        for(int r = 0; r<n; r++){
            if(strs[r][prev] > strs[r][i]) return false;
        }
        return true;
    }
    int getMaxSubLen(int i, int prev,  vector<string> &strs, vector<vector<int>>&dp){
   
        if(i ==  strs[0].size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int pick = 0;
        int notPick = 0;
        if(prev == -1 || isValid(i, prev, strs)){
            pick = 1 + getMaxSubLen(i + 1,i, strs, dp);
        } 
        notPick = 0 + getMaxSubLen(i + 1, prev, strs, dp);
        return dp[i][prev+1] = max(pick, notPick);

    }
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        vector<vector<int>>dp(n, vector<int>(n+1 , -1));
        return strs[0].size() - getMaxSubLen(0, -1, strs, dp);
    }
};