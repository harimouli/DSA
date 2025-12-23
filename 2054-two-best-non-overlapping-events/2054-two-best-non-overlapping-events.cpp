class Solution {
public:

    int getMaxValue(int ind, int prevEndTime, vector<vector<int>>& events, int cnt, vector<vector<vector<int>>> &dp){
        int n = events.size();

        if(ind == n) return 0;
        if(cnt == 2) return 0;
         if( dp[ind][prevEndTime+1][cnt] != -1){
            return dp[ind][prevEndTime+1][cnt];
        }
         
        int pick = 0;
        if(prevEndTime == -1 || events[ind][0] > events[prevEndTime][1] ){
                pick = events[ind][2] + getMaxValue(ind + 1, ind,events, cnt + 1, dp);
        }

        int notPick = 0 + getMaxValue(ind + 1, prevEndTime,events, cnt, dp);

        return dp[ind][prevEndTime+1][cnt] = max(pick, notPick);
    }
    static bool customSort(vector<int>& p1, vector<int> &p2){
        if(p1[0] == p2[0]) {
            return p1[1] < p2[1];
        }
        return p1[0] < p2[0];
    }

    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), customSort);
        int n = events.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n+1, vector<int>(3, -1)));


        return getMaxValue(0, -1,events, 0, dp);
        
    }
};