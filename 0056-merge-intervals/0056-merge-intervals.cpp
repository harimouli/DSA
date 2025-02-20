class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        int n = intervals.size();

        for(int i = 0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(!res.empty() && end <= res.back()[1] ){
                continue;
            }
            
            for(int j = i + 1; j<n; j++){
                if(end >= intervals[j][0]){
                    end = max(end, intervals[j][1]);
                }
                else {
                    break;
                }
            }

            res.push_back({start, end});

        }
        return res;
    }
};