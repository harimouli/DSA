class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int count = 0;
        int prevDay = 0;
        sort(meetings.begin(), meetings.end());
        for(auto meet : meetings){
            int start = meet[0];
            int end = meet[1];
            if(start <= prevDay){
                count += max(0, meet[1] - prevDay);
            }
            else{
                count += (end - start) + 1;
            }
            prevDay = max(prevDay, meet[1]);
        }
        return days - count;
    }
};