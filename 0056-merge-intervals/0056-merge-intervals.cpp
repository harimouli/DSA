class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();


        vector<vector<int>> res;

        for(int i = 0; i<n; i++){
            if(res.empty() || res.back()[1] < intervals[i][0]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        return res;
        
    }
};