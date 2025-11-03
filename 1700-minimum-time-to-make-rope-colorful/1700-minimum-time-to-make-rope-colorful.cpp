class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        

        int n = colors.size();
        int left = 0;
        int ans = 0;
        while(left<n){
            int conSum = neededTime[left];
            int maxTime = neededTime[left];
            while(left + 1 <  n && colors[left] == colors[left+1]){
                left++;
                conSum += neededTime[left];
                maxTime = max(maxTime, neededTime[left]);
            }
            ans += (conSum - maxTime);
            left++;
        }
        return ans;
    }
};