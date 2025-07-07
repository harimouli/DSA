class Solution {
public:
    static bool compare(const vector<int>&a, const vector<int> &b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int ans = 0;

        int limit = intervals[0][1];

        for(int i = 1; i<intervals.size(); i++){
             if(intervals[i][0] < limit){
                ans++;
             }
             else{
                limit = intervals[i][1];
             }
        }
        return ans;

    }
};