class Solution {
public:
    int minScoreTriangulation(vector<int>& values){
        int n=values.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return func(values,0,n-1,dp);
    }
    int func(vector<int> &values,int i,int j,vector<vector<int>> &dp){
        if(abs(i-j)<=1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i+1;k<j;k++){
            int current=func(values,i,k,dp)+func(values,k,j,dp)+values[i]*values[j]*values[k];
            mini=min(mini,current);
        }
        return dp[i][j]=mini;
    }
};